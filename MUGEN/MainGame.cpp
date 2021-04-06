#include "MainGame.h"
#include "Image.h"

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

	SceneManager::GetLpInstance()->Update();

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	SceneManager::GetLpInstance()->Render(hdc);

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



