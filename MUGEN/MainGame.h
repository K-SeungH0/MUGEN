#pragma once
#include "Mugen.h"
#include "Image.h"
#include "DIO.h"
class Image;
class King;
#include "Chang.h"
class MainGame
{
private:
	HDC hdc;
	PAINTSTRUCT ps;

	bool isInitialize = false;
	HWND hTimer;
	Image* backgroundCanvas;
	HDC hBackgroundDC;
	
	// 캐릭터 추가
	Character* lpKING;
	Image* bgImg;

	Character* lpDIO;


	Character* lpChang;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

