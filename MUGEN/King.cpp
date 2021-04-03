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

	motions[(int)CHARACTER_STATE::IDLE].offsetHitPos = { 0, 0 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_IDLE");
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_IDLE");
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetHitPos, 50, 120);

	motions[(int)CHARACTER_STATE::MOVE].offsetHitPos = { 10, 0 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_MOVE");
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_MOVE");
	motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetHitPos, 50, 120);
	
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos = { -30, 0 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_STRONGPUNCH");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_STRONGPUNCH");
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos, 50, 120);

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos = { -30, 0 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_WEAKPUNCH");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_WEAKPUNCH");
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos, 50, 120);

	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos = { -30, 0 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->GetImage("KING_RIGHT_SKILL");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->GetImage("KING_LEFT_SKILL");
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos, 50, 120);

	elapsedTime = 0;
	frame = 0;

	moveSpeed = 5;
}
