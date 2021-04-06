﻿#pragma once
#include "GameData.h"
//#include "Mugen.h"

class Image;
class Character;
class Controller;
class GameScene;

class InGame;
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

	GameScene* title;

	GameUI* title;
	
	SCENE_STATE currentScene;

	InGame* inGame;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);


};

