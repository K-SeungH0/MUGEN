#include "King.h"
#include "Image.h"

King::King()
{
}

King::~King()
{
}

void King::Init()
{
	dir = DIRECTION::LEFT;
	state = CHARACTER_STATE::IDLE;

	elapsedTime = 0;
	frame = 0;

	hp = 100;

	pos = { WINSIZE_WIDTH / 2, WINSIZE_HEIGHT / 2};

	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)DIRECTION::RIGHT] = { -20, -112 };
	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)DIRECTION::LEFT] = { -40, -112 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_IDLE");
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_IDLE");
	motions[(int)CHARACTER_STATE::IDLE].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::IDLE].width = 50;
	motions[(int)CHARACTER_STATE::IDLE].height = 100;
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetHitPos, 50, 120);

	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)DIRECTION::RIGHT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)DIRECTION::LEFT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::MOVE].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_MOVE");
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_MOVE");
	motions[(int)CHARACTER_STATE::MOVE].width = 50;
	motions[(int)CHARACTER_STATE::MOVE].height = 100;
	motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetHitPos, 50, 120);

	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)DIRECTION::RIGHT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)DIRECTION::LEFT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_MOVE");
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_MOVE");
	motions[(int)CHARACTER_STATE::MOVE_GUARD].width = 50;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].height = 100;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos, 50, 120);

	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos[(int)DIRECTION::RIGHT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos[(int)DIRECTION::LEFT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::GUARD].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::GUARD].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_GUARD");
	motions[(int)CHARACTER_STATE::GUARD].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_GUARD");
	motions[(int)CHARACTER_STATE::GUARD].width = 50;
	motions[(int)CHARACTER_STATE::GUARD].height = 100;
	motions[(int)CHARACTER_STATE::GUARD].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::GUARD].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::GUARD].motionSpeed = 30;

	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)DIRECTION::RIGHT] = { -40, -112 };
	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)DIRECTION::LEFT] = { -40, -112 };
	motions[(int)CHARACTER_STATE::HIT].offsetHitPos = { -30, -100 };
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_HIT1");
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_HIT1");
	motions[(int)CHARACTER_STATE::HIT].width = 50;
	motions[(int)CHARACTER_STATE::HIT].height = 100;
	motions[(int)CHARACTER_STATE::HIT].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::HIT].offsetHitPos, 50, 120);

	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)DIRECTION::RIGHT] = { -52, -112 };
	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)DIRECTION::LEFT] = { -104, -112 };
	motions[(int)CHARACTER_STATE::DEATH].offsetHitPos = { 0, 0 };
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_DEAD");
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_DEAD");
	motions[(int)CHARACTER_STATE::DEATH].width = 0;
	motions[(int)CHARACTER_STATE::DEATH].height = 0;
	motions[(int)CHARACTER_STATE::DEATH].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::DEATH].offsetHitPos, 0, 0);
	motions[(int)CHARACTER_STATE::DEATH].motionSpeed = 15;

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)DIRECTION::RIGHT] = { -23, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)DIRECTION::LEFT] = { -70, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_WEAKPUNCH");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_WEAKPUNCH");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].width = 50;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].height = 100;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {55,-85}, 40, 25, 5 }));

	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)DIRECTION::RIGHT] = { -35, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)DIRECTION::LEFT] = { -70, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_STRONGPUNCH");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_STRONGPUNCH");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].width = 50;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].height = 100;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {55,-85}, 50, 25, 10 }));

	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)DIRECTION::RIGHT] = { -43, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)DIRECTION::LEFT] = { -85, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_STRONGKICK");
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_STRONGKICK");
	motions[(int)CHARACTER_STATE::ATTACK_KICK].width = 50;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].height = 100;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {65,-85}, 60, 40, 10 }));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::MELEE, {65,-85}, 60, 40, 15 }));

	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)DIRECTION::RIGHT] = { -35, -107 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)DIRECTION::LEFT] = { -70, -107 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_SKILL");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_SKILL");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].width = 50;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].height = 100;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::RANGE, {120,-78}, 75, 40, 10, "KING_RIGHT_RANGE_ATTACK_COLLIDER", "KING_RIGHT_RANGE_ATTACK_EFFECT" }));

	elapsedTime = 0;
	frame = 0;

	moveSpeed = 5;
}

void King::Update()
{
	Character::Update();

	if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_NUMPAD4))
	{
		this->state = CHARACTER_STATE::IDLE;
	}
	if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_NUMPAD5))
	{
		this->state = CHARACTER_STATE::MOVE_GUARD;
	}	
	if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_NUMPAD6))
	{
		this->state = CHARACTER_STATE::ATTACK_RANGE;
	}
	if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_NUMPAD7))
	{
		this->state = CHARACTER_STATE::HIT;
	}
	if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_NUMPAD8))
	{
		this->state = CHARACTER_STATE::DEATH;
	}	
	if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_NUMPAD9))
	{
		this->state = CHARACTER_STATE::GUARD;
	}
	if (KeyManager::GetLpInstance()->IsOnceKeyDown('1'))
	{
		EffectManager::GetLpInstance()->EffectRender({ 100,100 }, ImageManager::GetLpInstance()->GetImage("KING_RIGHT_RANGE_ATTACK_EFFECT"));
	}
}


