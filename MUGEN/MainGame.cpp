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
		MessageBox(g_hWnd, "���ε� ����", "Error", MB_OK);
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

	// ĳ������ ��ġ ����
	// ĳ���ͳ��� �ε�������� ���� ����ġ��ŭ �з������� ó��
	RECT player1Rect = lpPlayer1->GetLpCharacter()->GetHitRect();
	RECT player2Rect = lpPlayer2->GetLpCharacter()->GetHitRect();
	if (CollisionRect(player1Rect, player2Rect))
	{
		// �浹
		// ������ ��ŭ �̵����Ѿ��Ѵ�
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

	// �浹ü ����
	ColliderManager::GetLpInstance()->Render(hBackDC);

	// ����Ʈ ����
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

			// �ݶ��̴��� ������ �ش� ĳ������ hitRect�� �߽ɰ� ���� �̾ hitRect�ȿ� ������ �� �������� ����Ʈ ���
			// KING_LEFT_RANGE_ATTACK_EFFECT
			incl = (it->pos.y - playerPoint.y) / (it->pos.x - playerPoint.x);
			point = { roundf(it->pos.x), incl * roundf(it->pos.x) + (it->pos.y - incl * it->pos.x) };
			if (playerPoint.x - it->pos.x < 0)
			{
				for (int i = 0; point.x + i >= playerPoint.x + 0.0001f; --i)
				{
					if (CollisionRectInPoint(playerRect, { (int)round(point.x + i + 0.0001f), (int)round(point.y + incl * i + 0.0001f) }))
					{
						// ����Ʈ ����� for�� ������
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
						// ����Ʈ ����� for�� ������
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
