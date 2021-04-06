#pragma once
#include "GameScene.h"
#include "Character.h"
#include "Controller.h"
#include "Singleton.h"

class InGame : public GameScene
{
public:
	InGame();
	~InGame();
private:
	Image* Player1_HPUI;
	Image* Player2_HPUI;
	Image* Player1_HP;
	Image* Player2_HP;
	Image* Player1_DelayHP;
	Image* Player2_DelayHP;
	Image* lpBuffer;
	Image* lpBgImg;
	Image* lpKOImg;
	Image* UI_Time;
	int x;

	int elapsedTime;
	int frame;
	int time = 60;

	Controller* lpPlayer1;
	Controller* lpPlayer2;
public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

};

