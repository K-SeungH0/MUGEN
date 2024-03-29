#include "Mugen.h"
#include "MainGame.h"

HINSTANCE g_hInstance;
HWND g_hWnd;
LPSTR g_lpszClass = (LPSTR)TEXT("=== Mugen ===");

bool isDebugMode;
MainGame g_mainGame;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdParam, int nCmdShow);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	g_hInstance = hInstance;

	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = g_hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass, WS_OVERLAPPEDWINDOW, 0, 0, WINSIZE_WIDTH, WINSIZE_HEIGHT, NULL, NULL, g_hInstance, NULL);
	RECT winRect = { 0,0,WINSIZE_WIDTH,WINSIZE_HEIGHT };
	AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(g_hWnd, NULL, 0, 0, winRect.right - winRect.left, winRect.bottom - winRect.top, SWP_NOMOVE | SWP_NOZORDER);

	ShowWindow(g_hWnd, nCmdShow);

	if (FAILED(g_mainGame.Init()))
	{
		MessageBox(g_hWnd, "메인게임 생성에 실패했습니다.", "Error", MB_OK);
		return 0;
	}

	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	g_mainGame.Release();

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return g_mainGame.WndProc(hWnd, iMessage, wParam, lParam);
}