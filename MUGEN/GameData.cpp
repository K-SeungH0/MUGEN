#include "GameData.h"
#include "King.h"
#include "Chang.h"
#include "DIO.h"
#include "Controller.h"
void GameData::Init()
{
	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		this->player[i].lp_Controller = new Controller();
		this->player[i].lp_Controller->Init();
	}
}

void GameData::Release()
{
	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		delete this->player[i].lp_Character;
		this->player[i].lp_Character = nullptr;
		
		delete this->player[i].lp_Controller;
		this->player[i].lp_Controller = nullptr;
	}
}

void GameData::GetCharacter(PLAYER_TYPE playerType, CHARACTER_NAME characterName)
{
	switch (characterName)
	{
		case CHARACTER_NAME::CHANG:
			this->player[(int)playerType].lp_Character = new Chang();
			this->player[(int)playerType].lp_Character->Init();
			break;
		case CHARACTER_NAME::DIO:
			this->player[(int)playerType].lp_Character = new DIO();
			this->player[(int)playerType].lp_Character->Init();
			break;
		case CHARACTER_NAME::KING:
			this->player[(int)playerType].lp_Character = new King();
			this->player[(int)playerType].lp_Character->Init();
			break;
	}
	
	this->player[(int)playerType].lp_Controller->SetController(playerType, this->player[(int)playerType].lp_Character);
}
