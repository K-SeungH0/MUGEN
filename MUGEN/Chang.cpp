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

	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_Idle");
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_Idle");
	motions[(int)CHARACTER_STATE::IDLE].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::IDLE].width = 70;
	motions[(int)CHARACTER_STATE::IDLE].height = 126;
	// MOVE
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_Move");
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_Move");
	motions[(int)CHARACTER_STATE::MOVE].offsetHitPos = { -34, -125 };
	motions[(int)CHARACTER_STATE::MOVE].width = 70;
	motions[(int)CHARACTER_STATE::MOVE].height = 126;

	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_BackMove");
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_BackMove");
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].width = 70;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].height = 126;

	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_Hit");
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_Hit");
	motions[(int)CHARACTER_STATE::HIT].offsetHitPos = { -5, -115 };
	motions[(int)CHARACTER_STATE::HIT].width = 100;
	motions[(int)CHARACTER_STATE::HIT].height = 115;
	motions[(int)CHARACTER_STATE::HIT].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::HIT].offsetHitPos, 100, 115);

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {63,-90}, 70, 50, 10 }));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {85,-90}, 90, 50, 15 }));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::RANGE, {120,-90}, 40, 40, 10 }));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::MELEE, {106,-46}, 60, 40, 10 }));

	// ATTACK_STRONG
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_RightPunch");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_RightPunch");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_LeftPunch");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_LeftPunch");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_RangeAttack");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_RangeAttack");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_RightKick");
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_LeftKick");
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)DIRECTION::RIGHT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)DIRECTION::LEFT] = { -327, -394 };
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("RightChang_Down");
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("LeftChang_Down");
	motions[(int)CHARACTER_STATE::DEATH].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::DEATH].width = 70;
	motions[(int)CHARACTER_STATE::DEATH].height = 126;
	motions[(int)CHARACTER_STATE::DEATH].hitRc = { 0, 0, 0, 0 };

	frame = 0;
	elapsedTime = 0;
	moveSpeed = 5;
}