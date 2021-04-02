#include "MainGame.h"

HRESULT MainGame::Init()
{
	hTimer = (HWND)SetTimer(g_hWnd, NULL, 10, NULL);

	backgroundCanvas = new Image();
	backgroundCanvas->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);
	hBackgroundDC = backgroundCanvas->GetMemDC();

	KeyManager::GetLpInstance()->Init();

	lpChang = new Chang();
	lpChang->Init();

	isInitialize = true;
	hTimer = (HWND)SetTimer(g_hWnd, 0, 10, NULL);
	return S_OK;
}

void MainGame::Release()
{
	lpChang->Release();
	delete lpChang;

	backgroundCanvas->Release();
	delete backgroundCanvas;

	KeyManager::GetLpInstance()->ReleaseSingleton();
}

void MainGame::Update()
{
	lpChang->Update();

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	HDC hBackDC = backgroundCanvas->GetMemDC();

	lpChang->Render(hBackDC);
	
}

LRESULT MainGame::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_TIMER:
		if (isInitialize) Update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		if (isInitialize) Render(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		KillTimer(hWnd, NULL);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
