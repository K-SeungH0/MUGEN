#pragma once
#include "GameData.h"
//#include "Mugen.h"

class Image;
class Character;
class Controller;
class GameUI;

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

	// 캐릭터 추가
	Character* lpKING;
	Character* lpDIO;
	Character* lpChang;

	Controller* lpPlayer1;
	Controller* lpPlayer2;

	GameUI* title;
	
	SCENE_STATE currentScene;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

private:
	bool IsCollision(Character* attacker, Character* defender);
};

