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
	Image* Time;
	Image* Time0;
	Image* Time1;
	Image* Time2;
	Image* Time3;
	Image* Time4;
	Image* Time5;
	Image* Time6;
	Image* Time7;
	Image* Time8;
	Image* Time9;

	int elapsedTime;
	int frame;
	int time = 60;
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

};

