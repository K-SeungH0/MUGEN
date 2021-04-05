#pragma once
#include "GameScene.h"
#include "Character.h"
#include "Controller.h"

class INGAME : public GameScene
{
private:
	Image* lpHP1UIImg;
	Image* lpHP2UIImg;
	Image* lpHP1Img;
	Image* lpHP2Img;
	Image* lpDelayHP1Img;
	Image* lpDelayHP2Img;
	Image* lpBuffer;
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

};

