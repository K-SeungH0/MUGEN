#pragma once
#include "Mugen.h"

class Image;
class King;
class MainGame
{
private:
	bool isInitialize = false;
	HWND hTimer;
	Image* backgroundCanvas;
	HDC hBackgroundDC;
	
	// ĳ���� �߰�
	King* king;
public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

