#pragma once
#include "Mugen.h"
#include "Image.h"
#include "DIO.h"

<<<<<<< HEAD
class Image;
class King;
=======
>>>>>>> f687fac708cc3330e4230ef1025398cc2d8b5ae6
class MainGame
{
private:
	HDC hdc;
	PAINTSTRUCT ps;

	bool isInitialize = false;
	HWND hTimer;
	Image* backgroundCanvas;
<<<<<<< HEAD
	HDC hBackgroundDC;
	
	// 캐릭터 추가
	King* king;
=======
	Image* bgImg;

	Character* lpDIO;

>>>>>>> f687fac708cc3330e4230ef1025398cc2d8b5ae6
public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

