#include "MainGame.h"
#include "Image.h"
#include "King.h"
#include "Chang.h"
#include "DIO.h"
#include "Controller.h"
#include "Title.h"
#include "GameData.h"
#include "INGAME.h"
#include "InGame.h"

HRESULT MainGame::Init()
{
	GameData::GetLpInstance()->Init();
	KeyManager::GetLpInstance()->Init();
	ColliderManager::GetLpInstance()->Init();
	ImageManager::GetLpInstance()->Init();
	
	title = new Title();
	title->Init();
	inGame = new InGame();
	inGame->Init();

	isInitialize = true;
	hTimer = (HWND)SetTimer(g_hWnd, 0, 10, NULL);
	return S_OK;
}

void MainGame::Release()
{
	inGame->Release();
	delete inGame;

	KeyManager::GetLpInstance()->ReleaseSingleton();
	ImageManager::GetLpInstance()->ReleaseSingleton();
}

void MainGame::Update()
{
	title->Update();
	inGame->Update();
	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	inGame->Render(hdc);
	
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


