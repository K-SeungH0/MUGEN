#include "MainGame.h"
#include "Image.h"
#include "King.h"

HRESULT MainGame::Init()
{
	hTimer = (HWND)SetTimer(g_hWnd, NULL, 10, NULL);

	backgroundCanvas = new Image();
	backgroundCanvas->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);
	hBackgroundDC = backgroundCanvas->GetMemDC();

	KeyManager::GetLpInstance()->Init();

	king = new King();
	king->Init();

	isInitialize = true;
	return S_OK;
}

void MainGame::Release()
{
	backgroundCanvas->Release();
	delete backgroundCanvas;

	KeyManager::GetLpInstance()->ReleaseSingleton();
}

void MainGame::Update()
{
	if (KeyManager::GetLpInstance()->IsOnceKeyDown('W'))
	{
		MessageBox(g_hWnd, "Once Key Down", "KeyDown", MB_OK);
	}
	if (KeyManager::GetLpInstance()->IsOnceKeyUp('D'))
	{
		MessageBox(g_hWnd, "Once Key Up", "KeyUp", MB_OK);
	}
	if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_SPACE))
	{
		MessageBox(g_hWnd, "Stay Key Down", "StayKeyDown", MB_OK);
	}

	king->Update();

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	king->Render(hdc);
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
