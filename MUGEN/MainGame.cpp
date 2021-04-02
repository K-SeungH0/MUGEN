#include "MainGame.h"
<<<<<<< HEAD
#include "Image.h"
#include "King.h"
=======
#include "DIO.h"
>>>>>>> f687fac708cc3330e4230ef1025398cc2d8b5ae6

HRESULT MainGame::Init()
{
	KeyManager::GetLpInstance()->Init();
	
	backgroundCanvas = new Image();
	backgroundCanvas->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);
	bgImg = new Image();
	if (FAILED(bgImg->Init("Image/UI/Battle/bgImage.bmp", WINSIZE_WIDTH, WINSIZE_HEIGHT)))
	{
		MessageBox(g_hWnd, "배경로드 실패", "Error", MB_OK);
	}

	lpDIO = new DIO();
	lpDIO->Init();

	king = new King();
	king->Init();

	isInitialize = true;
	hTimer = (HWND)SetTimer(g_hWnd, 0, 10, NULL);
	return S_OK;
}

void MainGame::Release()
{
	lpDIO->Release();
	delete lpDIO;

	bgImg->Release();
	delete bgImg;

	backgroundCanvas->Release();
	delete backgroundCanvas;

	KeyManager::GetLpInstance()->ReleaseSingleton();
}

void MainGame::Update()
{
<<<<<<< HEAD
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

=======
	lpDIO->Update();
>>>>>>> f687fac708cc3330e4230ef1025398cc2d8b5ae6
	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
<<<<<<< HEAD
	king->Render(hdc);
=======
	HDC hBackDC = backgroundCanvas->GetMemDC();
	bgImg->Render(hBackDC);

	lpDIO->Render(hBackDC);

	backgroundCanvas->Render(hdc);
>>>>>>> f687fac708cc3330e4230ef1025398cc2d8b5ae6
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
