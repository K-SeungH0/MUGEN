#include "MainGame.h"
#include "Image.h"
#include "King.h"
#include "Chang.h"
#include "DIO.h"
#include "Controller.h"
#include "Title.h"
#include "GameData.h"

HRESULT MainGame::Init()
{
	GameData::GetLpInstance()->Init();
	KeyManager::GetLpInstance()->Init();
	ColliderManager::GetLpInstance()->Init();
	ImageManager::GetLpInstance()->Init();
	
	lpBuffer = new Image();
	lpBuffer->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);

	lpBgImg = new Image();
	if (FAILED(lpBgImg->Init("Image/UI/Battle/bgImage.bmp", WINSIZE_WIDTH, WINSIZE_HEIGHT)))
	{
		MessageBox(g_hWnd, "배경 로드 실패", "Error", MB_OK);
	}

	lpDIO = new DIO();
	lpDIO->Init();

	lpKING = new King();
	lpKING->Init();

	lpChang = new Chang();
	lpChang->Init();

	lpPlayer1 = new Controller();
	lpPlayer1->Init();
	lpPlayer1->SetController(PLAYER_TYPE::P1, lpChang);

	lpPlayer2 = new Controller();
	lpPlayer2->Init();
	lpPlayer2->SetController(PLAYER_TYPE::P2, lpKING);

	//title = new Title();
	//title->Init();
	inGame = new InGame();
	inGame->Init();

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

	lpChang->Release();
	delete lpChang;

	lpBgImg->Release();
	delete lpBgImg;

	lpBuffer->Release();
	delete lpBuffer;

	inGame->Release();
	delete inGame;

	KeyManager::GetLpInstance()->ReleaseSingleton();
	ImageManager::GetLpInstance()->ReleaseSingleton();
}

void MainGame::Update()
{
	if (g_hWnd != GetForegroundWindow()) return;

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

	//title->Update();
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

	title->Render(hBackDC);
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

	playerRect = defender->GetHitRect();
	auto& lstColliders = ColliderManager::GetLpInstance()->GetLstColliders(attacker->GetPlayerType());
	for (auto it = lstColliders.begin(); it != lstColliders.end();)
	{
		targetRect = { (int)(it->pos.x - it->width / 2), (int)(it->pos.y - it->height / 2), (int)(it->pos.x + it->width / 2), (int)(it->pos.y + it->height / 2) };
		if (CollisionRect(playerRect, targetRect))
		{
			isCollision = true;
			defender->Hit(it->damage);
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
