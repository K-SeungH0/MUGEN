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
		player[i].lp_Character = nullptr;
		player[i].lp_Controller = new Controller();
		player[i].lp_Controller->Init();
	}

	LoadKeySet();
}

void GameData::Release()
{
	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		if (player[i].lp_Character != nullptr)
		{
			delete player[i].lp_Character;
			player[i].lp_Character = nullptr;
		}	

		if (player[i].lp_Controller != nullptr)
		{
			delete player[i].lp_Controller;
			player[i].lp_Controller = nullptr;
		}
	}
}

void GameData::SetCharacter(PLAYER_TYPE playerType, CHARACTER_NAME characterName)
{
	switch (characterName)
	{
		case CHARACTER_NAME::CHANG:
			player[(int)playerType].lp_Character = new Chang();
			player[(int)playerType].lp_Character->Init();
			break;
		case CHARACTER_NAME::DIO:
			player[(int)playerType].lp_Character = new DIO();
			player[(int)playerType].lp_Character->Init();
			break;
		case CHARACTER_NAME::KING:
			player[(int)playerType].lp_Character = new King();
			player[(int)playerType].lp_Character->Init();
			break;
	}
	
	player[(int)playerType].lp_Controller->SetController(playerType, player[(int)playerType].lp_Character);
}

void GameData::LoadKeySet()
{
	if (FileManager::GetLpInstance()->ReadFile("INI/INPUT_KEY.ini"))
	{
		string group = "1P";
		string up = FileManager::GetLpInstance()->GetData<string>(group, "UP");
		string down = FileManager::GetLpInstance()->GetData<string>(group, "DOWN");
		string left = FileManager::GetLpInstance()->GetData<string>(group, "LEFT");
		string right = FileManager::GetLpInstance()->GetData<string>(group, "RIGHT");
		string weakA = FileManager::GetLpInstance()->GetData<string>(group, "ATTACK_WEAK");
		string strongA = FileManager::GetLpInstance()->GetData<string>(group, "ATTACK_STRONG");
		string kick = FileManager::GetLpInstance()->GetData<string>(group, "ATTACK_KICK");
	}
	else
	{
		MessageBox(g_hWnd, "키셋팅 INI파일을 읽지 못하였습니다.", "Error", MB_OK);
	}
}
