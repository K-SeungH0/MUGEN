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
	name = "KING";
	dir = CHARACTER_DIRECTION::LEFT;
	state = CHARACTER_STATE::IDLE;

	elapsedTime = 0;
	frame = 0;

	hp = 100;

	pos = { WINSIZE_WIDTH / 2, WINSIZE_HEIGHT / 2};

	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -20, -112 };
	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -40, -112 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT,CHARACTER_STATE::IDLE));
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::IDLE));
	motions[(int)CHARACTER_STATE::IDLE].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::IDLE].width = 50;
	motions[(int)CHARACTER_STATE::IDLE].height = 100;
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::IDLE].motionSpeed = 7;	

	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::MOVE].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::MOVE));
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::MOVE));
	motions[(int)CHARACTER_STATE::MOVE].width = 50;
	motions[(int)CHARACTER_STATE::MOVE].height = 100;
	motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::MOVE].motionSpeed = 7;

	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::MOVE_GUARD));
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::MOVE_GUARD));
	motions[(int)CHARACTER_STATE::MOVE_GUARD].width = 50;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].height = 100;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::MOVE_GUARD].motionSpeed = 7;

	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -30, -112 };
	motions[(int)CHARACTER_STATE::GUARD].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::GUARD].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::GUARD));
	motions[(int)CHARACTER_STATE::GUARD].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::GUARD));
	motions[(int)CHARACTER_STATE::GUARD].width = 50;
	motions[(int)CHARACTER_STATE::GUARD].height = 100;
	motions[(int)CHARACTER_STATE::GUARD].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::GUARD].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::GUARD].motionSpeed = 5;

	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -30, -96 };
	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -30, -96 };
	motions[(int)CHARACTER_STATE::HIT].offsetHitPos = { -20, -100 };
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::HIT));
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::HIT));
	motions[(int)CHARACTER_STATE::HIT].width = 50;
	motions[(int)CHARACTER_STATE::HIT].height = 100;
	motions[(int)CHARACTER_STATE::HIT].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::HIT].offsetHitPos, 50, 120);
	motions[(int)CHARACTER_STATE::HIT].motionSpeed = 5;

	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -52, -112 };
	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -104, -112 };
	motions[(int)CHARACTER_STATE::DEATH].offsetHitPos = { 0, 0 };
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::DEATH));
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::DEATH));
	motions[(int)CHARACTER_STATE::DEATH].width = 0;
	motions[(int)CHARACTER_STATE::DEATH].height = 0;
	motions[(int)CHARACTER_STATE::DEATH].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::DEATH].offsetHitPos, 0, 0);
	motions[(int)CHARACTER_STATE::DEATH].motionSpeed = 7;

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -23, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -70, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::ATTACK_WEAK));
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::ATTACK_WEAK));
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].width = 50;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].height = 100;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos, 50, 120);
	//motions[(int)CHARACTER_STATE::ATTACK_WEAK].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {55,-85}, 40, 25, 5 }));
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].motionSpeed = 7;

	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -35, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -70, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::ATTACK_STRONG));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::ATTACK_STRONG));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].width = 50;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].height = 100;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos, 50, 120);
	//motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {55,-85}, 50, 25, 10 }));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].motionSpeed = 7;

	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -43, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -85, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::ATTACK_KICK));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::ATTACK_KICK));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].width = 50;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].height = 100;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos, 50, 120);
	//motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {65,-85}, 60, 40, 10 }));
	//motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::MELEE, {65,-85}, 60, 40, 15 }));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].motionSpeed = 7;

	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -35, -107 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -70, -107 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos = { -25, -100 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)CHARACTER_DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::RIGHT, CHARACTER_STATE::ATTACK_RANGE));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)CHARACTER_DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage(GetKey(name, CHARACTER_DIRECTION::LEFT, CHARACTER_STATE::ATTACK_RANGE));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].width = 50;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].height = 100;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos, 50, 120);
	//motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::RANGE, {120,-78}, 75, 40, 10, "KING_RIGHT_RANGE_ATTACK_COLLIDER", "KING_RIGHT_RANGE_ATTACK_EFFECT" }));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].motionSpeed = 7;

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


