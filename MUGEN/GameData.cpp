#include "GameData.h"
#include "King.h"
#include "Chang.h"
#include "DIO.h"
#include "Controller.h"
#include "FileManager.h"
void GameData::Init()
{
	player = new PlayerInfo[(int)PLAYER_TYPE::NONE];

	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		player[i].playerType = (PLAYER_TYPE)i;
		player[i].lpCharacter = nullptr;
		player[i].lpController = new Controller();
		player[i].lpController->Init();
	}
}

void GameData::Release()
{
	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		if (player[i].lpCharacter != nullptr)
		{
			delete player[i].lpCharacter;
			player[i].lpCharacter = nullptr;
		}	

		if (player[i].lpController != nullptr)
		{
			delete player[i].lpController;
			player[i].lpController = nullptr;
		}
	}
}

void GameData::SetCharacter(PLAYER_TYPE playerType, CHARACTER_NAME characterName)
{
	switch (characterName)
	{
		case CHARACTER_NAME::CHANG:
			player[(int)playerType].lpCharacter = new Chang();
			player[(int)playerType].lpCharacter->Init();
			break;
		case CHARACTER_NAME::DIO:
			player[(int)playerType].lpCharacter = new DIO();
			player[(int)playerType].lpCharacter->Init();
			break;
		case CHARACTER_NAME::KING:
			player[(int)playerType].lpCharacter = new King();
			player[(int)playerType].lpCharacter->Init();
			break;
	}
	
	player[(int)playerType].lpController->SetController(playerType, player[(int)playerType].lpCharacter);
}

void GameData::GameReset()
{
	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		if (player[i].lpCharacter != nullptr)
		{
			delete player[i].lpCharacter;
			player[i].lpCharacter = nullptr;
		}

		if (player[i].lpController != nullptr)
		{
			delete player[i].lpController;
			player[i].lpController = nullptr;
		}
	}

	Init();
}