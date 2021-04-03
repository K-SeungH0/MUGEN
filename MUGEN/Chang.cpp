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
	pos = { 100,  500 };
	name = "Chang Koehan";

	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos = { 327, 394 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_Idle");
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_Idle");
	motions[(int)CHARACTER_STATE::IDLE].offsetHitPos = { -47, -125 };
	motions[(int)CHARACTER_STATE::IDLE].width = 70;
	motions[(int)CHARACTER_STATE::IDLE].height = 126;

	// MOVE
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos = { 327, 394 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_Move");
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_Move");
	motions[(int)CHARACTER_STATE::MOVE].offsetHitPos = { -54, -125 };
	motions[(int)CHARACTER_STATE::MOVE].width = 70;
	motions[(int)CHARACTER_STATE::MOVE].height = 126;

	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos = { 327, 394 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_BackMove");
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_BackMove");
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos = { -47, -125 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].width = 70;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].height = 126;

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {53,-90}, 70, 50, 10 }));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {75,-90}, 90, 50, 15 }));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::RANGE, {120,-90}, 40, 40, 10 }));

	// ATTACK_STRONG
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos = { 327, 394 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_RightPunch");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_RightPunch");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos = { -47, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos = { 327, 394 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_LeftPunch");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_LeftPunch");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos = { -47, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos = { 327, 394 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_RangeAttack");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_RangeAttack");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos = { -47, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos, 0, 0);

	frame = 0;
	elapsedTime = 0;
	moveSpeed = 5;
}