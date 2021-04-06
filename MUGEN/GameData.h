#pragma once
#include "Singleton.h"
#include "Mugen.h"

class Character;
class Controller;
class GameData : public Singleton<GameData>
{
public:
	struct PlayerInfo
	{
		PLAYER_TYPE playerType;
		Character* lp_Character;
		Controller* lp_Controller;
	};
private:
	PlayerInfo player[(int)PLAYER_TYPE::NONE];

public:
	void Init();
	void Release();
	
	void GetCharacter(PLAYER_TYPE playerType, CHARACTER_NAME characterName);
};