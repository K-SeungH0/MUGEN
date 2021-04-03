#pragma once
#include "Mugen.h"

class Image;
class Character;
class Controller;
class MainGame
{
private:
	HDC hdc;
	PAINTSTRUCT ps;

	bool isInitialize = false;
	HWND hTimer;

	Image* lpBuffer;
	Image* lpBgImg;

	// 캐릭터 추가
	Character* lpKING;
	Character* lpDIO;
	Character* lpChang;

	Controller* lpPlayer1;
	Controller* lpPlayer2;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

