#include "Character.h"
#include "Image.h"

void Character::Init()
{
}

void Character::Release()
{
}

void Character::Update()
{
	if (!IsAlive())
	{
		// 죽었을때 마지막 프레임에서 멈추기
		if (frame == motions[(int)state].lpImages[(int)dir]->GetImageInfo()->maxFrame) return;
	}

	if (elapsedTime++ % motions[(int)state].motionSpeed == 0)
	{
		++frame %= motions[(int)state].lpImages[(int)dir]->GetImageInfo()->maxFrame;

		if (motions[(int)state].mAtkInfo.find(frame) != motions[(int)state].mAtkInfo.end())
		{
			// 공격할 위치가 존재 하다면 공격!
			POINTFLOAT atkPos;
			switch (motions[(int)state].mAtkInfo[frame].type)
			{
			case ATTACK_TYPE::MELEE:
				if (dir == DIRECTION::LEFT) atkPos = { pos.x - motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
				else atkPos = { pos.x + motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
				ColliderManager::GetLpInstance()->Create(type, atkPos, motions[(int)state].mAtkInfo[frame].width, motions[(int)state].mAtkInfo[frame].height);
				break;
			case ATTACK_TYPE::RANGE:
				if (dir == DIRECTION::LEFT)
				{
					atkPos = { pos.x - motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
					ColliderManager::GetLpInstance()->Fire(type, atkPos, motions[(int)state].mAtkInfo[frame].width, motions[(int)state].mAtkInfo[frame].height, 5, PI);
				}
				else
				{
					atkPos = { pos.x + motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
					ColliderManager::GetLpInstance()->Fire(type, atkPos, motions[(int)state].mAtkInfo[frame].width, motions[(int)state].mAtkInfo[frame].height, 5, 0);
				}
				break;
			}
		}
	}

	motions[(int)state].hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}

void Character::Render(HDC hdc)
{
	if (isDebugMode)
	{
		RECT rc;
		Rectangle(hdc, motions[(int)state].hitRc.left, motions[(int)state].hitRc.top, motions[(int)state].hitRc.right, motions[(int)state].hitRc.bottom);

		Ellipse(hdc, pos.x - 10, pos.y - 10, pos.x + 10, pos.y + 10);
	}

	POINTFLOAT drawPos = { pos.x + motions[(int)state].offsetDrawPos[(int)dir].x, pos.y + motions[(int)state].offsetDrawPos[(int)dir].y };
	if (motions[(int)state].lpImages[(int)dir]) motions[(int)state].lpImages[(int)dir]->Render(hdc, drawPos.x, drawPos.y, frame);
}

void Character::Hit(int damage)
{
	elapsedTime = 0;
	frame = 0;

	if (state != CHARACTER_STATE::MOVE_GUARD && state != CHARACTER_STATE::GUARD)
		state = CHARACTER_STATE::HIT;
	else
		state = CHARACTER_STATE::GUARD;

	if (state != CHARACTER_STATE::GUARD) hp -= damage;
	else
	{
		damage *= 0.1f;
		if (damage <= 0) damage = 1;
		hp -= damage;
	}
	
	if (hp <= 0)
	{
		hp = 0;
		state = CHARACTER_STATE::DEATH;
	}
}

void Character::Guard()
{
	frame = 0;
	elapsedTime = 0;
	state = CHARACTER_STATE::GUARD;
}

void Character::LeftMove()
{
	switch (state)
	{
	case Character::CHARACTER_STATE::IDLE:
	case Character::CHARACTER_STATE::MOVE:
	case Character::CHARACTER_STATE::MOVE_GUARD:
		pos.x -= moveSpeed;
		if (pos.x < 0) pos.x = 0;
		if (dir != DIRECTION::RIGHT) state = CHARACTER_STATE::MOVE_GUARD;
		else state = CHARACTER_STATE::MOVE;
		break;
	}
}

void Character::RightMove()
{
	switch (state)
	{
	case Character::CHARACTER_STATE::IDLE:
	case Character::CHARACTER_STATE::MOVE:
	case Character::CHARACTER_STATE::MOVE_GUARD:
		pos.x += moveSpeed;
		if (pos.x > WINSIZE_WIDTH) pos.x = WINSIZE_WIDTH;
		if (dir == DIRECTION::LEFT) state = CHARACTER_STATE::MOVE_GUARD;
		else state = CHARACTER_STATE::MOVE;
		break;
	}
}

void Character::WeakAttack()
{
	frame = 0;
	elapsedTime = 0;
	state = CHARACTER_STATE::ATTACK_WEAK;

	//MessageBox(g_hWnd, "일반 공격 커멘드 입력", "커멘드", MB_OK);
}

void Character::StrongAttack()
{
	frame = 0;
	elapsedTime = 0;
	state = CHARACTER_STATE::ATTACK_STRONG;

	//MessageBox(g_hWnd, "강한 공격 커멘드 입력", "커멘드", MB_OK);
}

void Character::KickAttack()
{
	frame = 0;
	elapsedTime = 0;
	state = CHARACTER_STATE::ATTACK_KICK;
}

void Character::RangeAttack()
{
	frame = 0;
	elapsedTime = 0;
	state = CHARACTER_STATE::IDLE;

	//MessageBox(g_hWnd, "원거리 공격 커멘드 입력", "커멘드", MB_OK);
}
