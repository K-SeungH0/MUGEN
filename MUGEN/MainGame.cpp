#include "MainGame.h"
#include "Image.h"
#include "King.h"
#include "Chang.h"
#include "DIO.h"
#include "Controller.h"

HRESULT MainGame::Init()
{
	KeyManager::GetLpInstance()->Init();
	ColliderManager::GetLpInstance()->Init();
	ImageManager::GetLpInstance()->Init();
	
	lpBuffer = new Image();
	lpBuffer->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);

	lpBgImg = new Image();
	if (FAILED(lpBgImg->Init("Image/UI/Battle/bgImage.bmp", WINSIZE_WIDTH, WINSIZE_HEIGHT)))
	{
		MessageBox(g_hWnd, "배경로드 실패", "Error", MB_OK);
	}

	lpDIO = new DIO();
	lpDIO->Init();

	lpKING = new DIO();
	lpKING->Init();

	//lpChang = new Chang();
	//lpChang->Init();

	lpPlayer1 = new Controller();
	lpPlayer1->Init();
	lpPlayer1->SetController(PLAYER_TYPE::P1, lpDIO);

	lpPlayer2 = new Controller();
	lpPlayer2->Init();
	lpPlayer2->SetController(PLAYER_TYPE::P2, lpKING);

	isInitialize = true;
	hTimer = (HWND)SetTimer(g_hWnd, 0, 10, NULL);
	return S_OK;
}

void MainGame::Release()
{
	lpDIO->Release();
	delete lpDIO;

	lpKING->Release();
	delete lpKING;

	//lpChang->Release();
	//delete lpChang;

	lpBgImg->Release();
	delete lpBgImg;

	lpBuffer->Release();
	delete lpBuffer;

	KeyManager::GetLpInstance()->ReleaseSingleton();
	ImageManager::GetLpInstance()->ReleaseSingleton();
}

void MainGame::Update()
{
	//if (g_hWnd != GetForegroundWindow()) return;

	if (KeyManager::GetLpInstance()->IsOnceKeyDown('P'))
	{
		isDebugMode = !isDebugMode;
	}

	ColliderManager::GetLpInstance()->Update();

	lpPlayer1->Update();
	lpPlayer2->Update();

	// 캐릭터의 위치 조정
	// 캐릭터끼리 부딪혔을경우 서로 일정치만큼 밀려나도록 처리
	RECT player1Rect = lpPlayer1->GetLpCharacter()->GetHitRect();
	RECT player2Rect = lpPlayer2->GetLpCharacter()->GetHitRect();
	if (CollisionRect(player1Rect, player2Rect))
	{
		// 충돌
		// 겹쳐진 만큼 이동시켜야한다
		float diffX = (player1Rect.right - player1Rect.left) + (player2Rect.right - player2Rect.left) - (max(player1Rect.right, player2Rect.right) - min(player1Rect.left, player2Rect.left));
		lpPlayer1->GetLpCharacter()->Translate({ -diffX / 2, 0 });
		lpPlayer2->GetLpCharacter()->Translate({ -diffX / 2, 0 });
	}

	IsCollision(lpPlayer1->GetLpCharacter(), lpPlayer2->GetLpCharacter());
	IsCollision(lpPlayer2->GetLpCharacter(), lpPlayer1->GetLpCharacter());

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	HDC hBackDC = lpBuffer->GetMemDC();

	lpBgImg->Render(hBackDC);

	lpPlayer1->Render(hBackDC);
	lpPlayer2->Render(hBackDC);

	// 충돌체 렌더
	ColliderManager::GetLpInstance()->Render(hBackDC);

	// 이펙트 렌더
	EffectManager::GetLpInstance()->Render(hBackDC);

	MoveToEx(hBackDC, 0, WINSIZE_HEIGHT - 100, nullptr);
	LineTo(hBackDC, WINSIZE_WIDTH, WINSIZE_HEIGHT - 100);
	lpBuffer->Render(hdc);
}

LRESULT MainGame::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_TIMER:
		if (isInitialize) Update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(g_hWnd, &ps);
		if (isInitialize) Render(hdc);
		EndPaint(g_hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		KillTimer(g_hWnd, NULL);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

bool MainGame::IsCollision(Character* attacker, Character* defender)
{
	bool isCollision = false;
	RECT playerRect = {}, targetRect = {};
	POINTFLOAT point, playerPoint;
	float incl = 1;

	playerRect = defender->GetHitRect();
	playerPoint = { defender->GetPos().x, defender->GetPos().y - (playerRect.bottom - playerRect.top) / 2 };
	auto& lstColliders = ColliderManager::GetLpInstance()->GetLstColliders(attacker->GetPlayerType());
	for (auto it = lstColliders.begin(); it != lstColliders.end();)
	{
		targetRect = { (int)(it->pos.x - it->width / 2), (int)(it->pos.y - it->height / 2), (int)(it->pos.x + it->width / 2), (int)(it->pos.y + it->height / 2) };
		if (CollisionRect(playerRect, targetRect))
		{
			isCollision = true;

			// 콜라이더의 원정과 해당 캐릭터의 hitRect의 중심과 선을 이어서 hitRect안에 있을때 그 지점에서 이펙트 출력
			// KING_LEFT_RANGE_ATTACK_EFFECT
			incl = (it->pos.y - playerPoint.y) / (it->pos.x - playerPoint.x);
			point = { roundf(it->pos.x), incl * roundf(it->pos.x) + (it->pos.y - incl * it->pos.x) };
			if (playerPoint.x - it->pos.x < 0)
			{
				for (int i = 0; point.x + i >= playerPoint.x + 0.0001f; --i)
				{
					if (CollisionRectInPoint(playerRect, { (int)round(point.x + i + 0.0001f), (int)round(point.y + incl * i + 0.0001f) }))
					{
						// 이펙트 출력후 for문 나가기
						point = { (float)round(point.x + i + 0.0001f), (float)round(point.y + incl * i + 0.0001f) };
						break;
					}
				}
			}
			else
			{
				for (int i = 0; point.x + i < playerPoint.x + 0.0001f; ++i)
				{
					if (CollisionRectInPoint(playerRect, { (int)round(point.x + i + 0.0001f), (int)round(point.y + incl * i + 0.0001f) }))
					{
						// 이펙트 출력후 for문 나가기
						point = { (float)round(point.x + i + 0.0001f), (float)round(point.y + incl * i + 0.0001f) };
						break;
					}
				}
			}
			/* it->hitEffectKey */
			defender->Hit(it->damage, point, "KING_RIGHT_RANGE_ATTACK_EFFECT");

			if (isDebugMode && it->type == ColliderManager::COLLIDER_TYPE::STATIC)
			{
				++it;
			}
			else
			{
				it = lstColliders.erase(it);
			}
		}
		else ++it;
	}

	return isCollision;
}
