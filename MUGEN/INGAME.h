#pragma once
#include "GameScene.h"
#include "Character.h"
#include "Controller.h"

class InGame : public GameScene
{
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
	Image* UI_Player1;
	Image* UI_Player2;

	int elapsedTime;
	int frame;
	int time = 60;

	Controller* lpPlayer1;
	Controller* lpPlayer2;

	// ±è½ÂÈ£ Ãß°¡ //
	Character* lpP1_Character;
	Character* lpP2_Character;
public:
	InGame();
	~InGame();
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);
	// ±è½ÂÈ£ Ãß°¡ //
	void Load();
private:
	bool IsCollision(Character* attacker, Character* defender);

};

