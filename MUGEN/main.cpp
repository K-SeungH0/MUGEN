#include "Mugen.h"
#include "MainGame.h"

HINSTANCE g_hInstance;
HWND g_hWnd;
LPSTR g_lpszClass = (LPSTR)TEXT("=== Mugen ===");

MainGame g_mainGame;

HRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdParam, int nCmdShow);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	g_hInstance = hInstance;

	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(g_hInstance, IDC_ARROW);
	wndClass.hIcon = LoadIcon(g_hInstance, IDI_APPLICATION);
	wndClass.hInstance = g_hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass, WS_OVERLAPPEDWINDOW, 0, 0, WINSIZE_WIDTH, WINSIZE_HEIGHT, NULL, NULL, g_hInstance, NULL);

	ShowWindow(g_hWnd, nCmdShow);

	MSG message;
	while (GetMessage(&message, g_hWnd, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

HRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return g_mainGame.WndProc(hWnd, iMessage, wParam, lParam);
}