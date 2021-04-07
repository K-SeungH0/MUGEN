#pragma once
#include "GameScene.h"

class InGame : public GameScene
{
private:
	Image* lpPlayer1HpUi;
	Image* lpPlayer2HpUi;
	Image* lpPlayer1Hp;
	Image* lpPlayer2Hp;
	Image* lpPlayer1DelayHp;
	Image* lpPlayer2DelayHp;
	Image* lpBuffer;
	Image* lpTime;
	Image* lpPlayer1Ui;
	Image* lpPlayer2Ui;
	Image* lpKoImg;
	Image* lpKo;

	int count = 0;
	int elapsedTime;
	int frame;
	int time = 60;

	bool IsCollision(Character* attacker, Character* defender);


	Controller* lpControllerP1;
	Controller* lpControllerP2;
	Character* lpCharacterP1;
	Character* lpCharacterP2;

public:
	InGame();
	~InGame();
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

