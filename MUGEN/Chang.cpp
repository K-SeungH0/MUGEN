#include "Mugen.h"
#include "Chang.h"
#include "Image.h"

Chang::Chang()
{
}

Chang::~Chang()
{
}

void Chang::Init()
{

	dir = DIRECTION::LEFT;
	state = CHARACTER_STATE::IDLE;
	hp = 100;
	pos = { -300,  300 };
	name = "Chang Koehan";


	lpImage = new Image();
	auto del_RGB = RGB(140, 206, 156);

	motions[(int)CHARACTER_STATE::IDLE].offsetPos = { -33, -120 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("RightChang_Idle", 0);
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("LeftChang_Idle", 0);
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetPos, 10000, 10000);
	// MOVE
	motions[(int)CHARACTER_STATE::MOVE].offsetPos = { -40, -120 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("RightChang_Move", 0);
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("LeftChang_Move", 0);
	motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetPos, 10000, 10000);


	// ATTACK_STRONG
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetPos = { -40, -120 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("RightChang_RightPunch", 0);
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("LeftChang_RightPunch", 0);
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetPos, 10000, 10000);

	frame = 0;
	elapsedTime = 0;
	moveSpeed = 5;
}