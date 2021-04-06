#pragma once
#include "Mugen.h"

class Image;
class Character;
class Controller;
class GameScene;

class MainGame
{
private:
	HDC hdc;
	PAINTSTRUCT ps;

	bool isInitialize = false;
	HWND hTimer;

	Image* lpBuffer;
	Image* lpBgImg;

	GameData::PlayerInfo players[(int)PLAYER_TYPE::NONE];
public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);


};

