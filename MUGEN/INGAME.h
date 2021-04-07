#pragma once
#include "GameScene.h"

class InGame : public GameScene
{
private:
	Image* lpPlayer1_HpUi;
	Image* lpPlayer2_HpUi;
	Image* lpPlayer1_Hp;
	Image* lpPlayer2_Hp;
	Image* lpPlayer1_DelayHp;
	Image* lpPlayer2_DelayHp;
	Image* lpBuffer;
	Image* lpKOImg;
	Image* lpUi_Time;
	Image* lpUi_Player1;
	Image* lpUi_Player2;
	Image* lpKo;

	int count = 0;
	int elapsedTime;
	int frame;
	int time = 60;

	bool IsCollision(Character* attacker, Character* defender);


	Controller* lpController_P1;
	Controller* lpController_P2;
	Character* lpCharacter_P1;
	Character* lpCharacter_P2;

public:
	InGame();
	~InGame();
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

