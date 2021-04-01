#pragma once
#include "Mugen.h"
#include "Image.h"
#include "DIO.h"

class MainGame
{
private:
	HDC hdc;
	PAINTSTRUCT ps;

	bool isInitialize = false;
	HWND hTimer;
	Image* backgroundCanvas;
	Image* bgImg;

	Character* lpDIO;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

