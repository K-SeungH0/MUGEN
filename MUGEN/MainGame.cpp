#include "MainGame.h"
#include "Image.h"
#include "King.h"
#include "Chang.h"
#include "DIO.h"
#include "Controller.h"
#include "Title.h"
#include "GameData.h"
#include "INGAME.h"

HRESULT MainGame::Init()
{
	GameData::GetLpInstance()->Init();
	KeyManager::GetLpInstance()->Init();
	ColliderManager::GetLpInstance()->Init();
	ImageManager::GetLpInstance()->Init();
	SceneManager::GetLpInstance()->Init();

	isInitialize = true;
	hTimer = (HWND)SetTimer(g_hWnd, 0, 10, NULL);
	return S_OK;
}

void MainGame::Release()
{
	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		delete this->players[i].lp_Character;
		this->players[i].lp_Character = nullptr;

		delete this->players[i].lp_Controller;
		this->players[i].lp_Controller = nullptr;
	}
	
	// 메인에 필요?
	//lpBgImg->Release();
	//delete lpBgImg;
	//
	//lpBuffer->Release();
	//delete lpBuffer;

	GameData::GetLpInstance()->ReleaseSingleton();
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
	SceneManager::GetLpInstance()->Update();
	//currentScene[(int)currentStage]->Update();
	
	// INGAME에 추가
	//	ColliderManager::GetLpInstance()->Update();
	//	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	//	{
	//		players[i].lp_Controller->Update();
	//	}
	//	// 캐릭터의 위치 조정
	//	// 캐릭터끼리 부딪혔을경우 서로 일정치만큼 밀려나도록 처리
	//	RECT player1Rect = players[(int)PLAYER_TYPE::P1].lp_Controller->GetLpCharacter()->GetHitRect();
	//	RECT player2Rect = players[(int)PLAYER_TYPE::P2].lp_Controller->GetLpCharacter()->GetHitRect();
	//	if (CollisionRect(player1Rect, player2Rect))
	//	{
	//		// 충돌
	//		// 겹쳐진 만큼 이동시켜야한다
	//		float diffX = (player1Rect.right - player1Rect.left) + (player2Rect.right - player2Rect.left) - (max(player1Rect.right, player2Rect.right) - min(player1Rect.left, player2Rect.left));
	//		players[(int)PLAYER_TYPE::P1].lp_Controller->GetLpCharacter()->Translate({ -diffX / 2, 0 });
	//		players[(int)PLAYER_TYPE::P2].lp_Controller->GetLpCharacter()->Translate({ -diffX / 2, 0 });
	//	}
	//
	//	IsCollision(players[(int)PLAYER_TYPE::P1].lp_Controller->GetLpCharacter(), players[(int)PLAYER_TYPE::P2].lp_Controller->GetLpCharacter());
	//	IsCollision(players[(int)PLAYER_TYPE::P2].lp_Controller->GetLpCharacter(), players[(int)PLAYER_TYPE::P1].lp_Controller->GetLpCharacter());


	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	// 메인에도 필요한가?
	//HDC hBackDC = lpBuffer->GetMemDC();

	SceneManager::GetLpInstance()->Render(hdc);
	//currentScene[(int)currentStage]->Render(hBackDC);

	//INGAME에 추가
	//lpBgImg->Render(hBackDC);
	//
	//lpPlayer1->Render(hBackDC);
	//lpPlayer2->Render(hBackDC);
	//
	//// 충돌체 렌더
	//ColliderManager::GetLpInstance()->Render(hBackDC);
	//
	//// 이펙트 렌더
	//EffectManager::GetLpInstance()->Render(hBackDC);
	//
	//MoveToEx(hBackDC, 0, WINSIZE_HEIGHT - 100, nullptr);
	//LineTo(hBackDC, WINSIZE_WIDTH, WINSIZE_HEIGHT - 100);

	//lpBuffer->Render(hdc);
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
