#pragma once
#include "Mugen.h"

class Image;
class MainGame
{
private:
	bool isInitialize = false;
	HWND hTimer;
	Image* backgroundCanvas;
	HDC hBackgroundDC;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	HRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

