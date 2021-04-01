#include "MainGame.h"

HRESULT MainGame::Init()
{
	hTimer = (HWND)SetTimer(g_hWnd, NULL, 10, NULL);
	isInitialize = true;
	return S_OK;
}

void MainGame::Release()
{
}

void MainGame::Update()
{
	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	
}

HRESULT MainGame::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
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
