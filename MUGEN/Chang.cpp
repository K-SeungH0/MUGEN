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

	dir = CHARACTER_DIRECTION::LEFT;
	state = CHARACTER_STATE::IDLE;
	hp = 100;
	pos = { 100,  WINSIZE_HEIGHT - 100 };
	name = "Chang Koehan";

	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -80, -149 };
	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -80, -149 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_IDLE");
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_IDLE");
	motions[(int)CHARACTER_STATE::IDLE].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::IDLE].width = 70;
	motions[(int)CHARACTER_STATE::IDLE].height = 126;
	// MOVE
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -80, -159 };
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -80, -159 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_MOVE");
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_MOVE");
	motions[(int)CHARACTER_STATE::MOVE].offsetHitPos = { -17, -125 };
	motions[(int)CHARACTER_STATE::MOVE].width = 70;
	motions[(int)CHARACTER_STATE::MOVE].height = 126;
	motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetHitPos, 50, 115);

	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -80, -159 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -80, -159 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_BACKMOVE");
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_BACKMOVE");
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos = { -35, -125 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].width = 70;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].height = 126;

	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -125, -159 };
	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -125, -159 };
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_HIT");
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_HIT");
	motions[(int)CHARACTER_STATE::HIT].offsetHitPos = { -27, -115 };
	motions[(int)CHARACTER_STATE::HIT].width = 70;
	motions[(int)CHARACTER_STATE::HIT].height = 115;
	motions[(int)CHARACTER_STATE::HIT].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::HIT].offsetHitPos, 100, 115);

	//motions[(int)CHARACTER_STATE::ATTACK_WEAK].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {63,-90}, 70, 50, 10 }));
	//motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::MELEE, {85,-90}, 90, 50, 15 }));
	//motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {106,-46}, 60, 40, 10 }));

	// ATTACK_STRONG
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -81, -160 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -81, -159 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_ATTACK_STRONG");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_ATTACK_STRONG");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -80, -165 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -80, -159 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_ATTACK_WEAK");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_ATTACK_WEAK");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].width = 70;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -80, -163 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -80, -163 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_RANGE_ATTACK");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_RANGE_ATTACK");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos = { -47, -111 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].width = 100;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].height = 112;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos, 0, 0);

	//motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::RANGE, {100,-100}, 40, 40, 10, "Chang_RIGHT_RANGE_ATTACK_COLLIDER", "" }));


	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -80, -159 };
	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -36, -117 };
	motions[(int)CHARACTER_STATE::GUARD].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_GUARD");
	motions[(int)CHARACTER_STATE::GUARD].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_GUARD");
	motions[(int)CHARACTER_STATE::GUARD].offsetHitPos = { -25, -125 };
	motions[(int)CHARACTER_STATE::GUARD].width = 50;
	motions[(int)CHARACTER_STATE::GUARD].height = 125;
	motions[(int)CHARACTER_STATE::GUARD].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::GUARD].offsetHitPos, 50, 115);

	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -80, -158 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -80, -159 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_ATTACK_KICK");
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_ATTACK_KICK");
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos = { -27, -125 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].width = 90;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].height = 126;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos, 0, 0);

	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -171, -178 };
	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -171, -178 };
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("Chang_RIGHT_DOWN");
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("Chang_LEFT_DOWN");
	motions[(int)CHARACTER_STATE::DEATH].offsetHitPos = { -127, -70 };
	motions[(int)CHARACTER_STATE::DEATH].width = 126;
	motions[(int)CHARACTER_STATE::DEATH].height = 70;
	motions[(int)CHARACTER_STATE::DEATH].hitRc = { 0, 0, 0, 0 };

	frame = 0;
	elapsedTime = 0;
	moveSpeed = 5;
}