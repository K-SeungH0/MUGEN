#pragma once
#include "Singleton.h"

class Character;
class Controller;
enum class PLAYER_TYPE;
class GameData : public Singleton<GameData>
{
public:
	enum class CHARACTER_NAME
	{
		CHANG,
		DIO,
		KING,
		NONE
	};
	struct PlayerInfo
	{
		PLAYER_TYPE playerType;
		Character* lp_Character;
		Controller* lp_Controller;
	};

private:
	PlayerInfo* player;

public:
	void Init();
	void Release();

	void SetCharacter(PLAYER_TYPE playerType, CHARACTER_NAME characterName);
	inline PlayerInfo GetPlayer(PLAYER_TYPE playerType) { return player[(int)playerType]; }
};