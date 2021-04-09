#pragma once
#include "GameScene.h"

class InGame : public GameScene
{
private:
	enum class INGAME_STATE
	{
		INTRO,
		REALTIME,
		TURN_P1,
		TURN_P2
	};

	INGAME_STATE state;

	Image* lpBuffer;
	Image* lpPlayer1HpUi;
	Image* lpPlayer2HpUi;
	Image* lpPlayerHp;
	Image* lpPlayerDelayHp;
	Image* lpTime;
	Image* lpPlayer1Ui;
	Image* lpPlayer2Ui;
	Image* lpKoImg;
	Image* lpKo;

	int count = 0;
	int elapsedTime;
	int frame;
	int time = 60;

	float prePlayerHp1;
	float prePlayerHp2;

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

	bool IsCollision(Character* attacker, Character* defender);
};

