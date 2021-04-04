#include "Character.h"
#include "Image.h"

void Character::Init()
{
	priority = -1;
}

void Character::Release()
{
}

void Character::Update()
{
	if (!IsAlive())
	{
		// 죽었을때 마지막 프레임에서 멈추기
		if (frame + 1 == motions[(int)state].lpImages[(int)dir]->GetImageInfo()->maxFrame) return;
	}

	if (elapsedTime++ % motions[(int)state].motionSpeed == 9)
	{
		++frame %= motions[(int)state].lpImages[(int)dir]->GetImageInfo()->maxFrame;
		if (frame == 0)
		{
			// 모션이 한사이클 끝남
			switch (state)
			{
			case Character::CHARACTER_STATE::GUARD:
				state = CHARACTER_STATE::MOVE_GUARD;
				break;
			case Character::CHARACTER_STATE::ATTACK_WEAK:
			case Character::CHARACTER_STATE::ATTACK_STRONG:
			case Character::CHARACTER_STATE::ATTACK_KICK:
			case Character::CHARACTER_STATE::ATTACK_RANGE:
			case Character::CHARACTER_STATE::HIT:
				state = CHARACTER_STATE::IDLE;
				priority = -1;
				break;
			}
		}

		if (motions[(int)state].mAtkInfo.find(frame) != motions[(int)state].mAtkInfo.end())
		{
			// 공격할 위치가 존재 하다면 공격!
			POINTFLOAT atkPos;
			switch (motions[(int)state].mAtkInfo[frame].type)
			{
			case ATTACK_TYPE::MELEE:
				if (dir == DIRECTION::LEFT) atkPos = { pos.x - motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
				else atkPos = { pos.x + motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
				ColliderManager::GetLpInstance()->Create(type, atkPos,
													motions[(int)state].mAtkInfo[frame].width,
													motions[(int)state].mAtkInfo[frame].height,
													motions[(int)state].mAtkInfo[frame].hitEffectKey,
													10);
				break;
			case ATTACK_TYPE::RANGE:
				if (dir == DIRECTION::LEFT)
				{
					atkPos = { pos.x - motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
					ColliderManager::GetLpInstance()->Fire(
									type, atkPos, 
									motions[(int)state].mAtkInfo[frame].width,
									motions[(int)state].mAtkInfo[frame].height,
									5, PI,
									motions[(int)state].mAtkInfo[frame].imageKey,
									motions[(int)state].mAtkInfo[frame].hitEffectKey,
									10);
				}
				else
				{
					atkPos = { pos.x + motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
					ColliderManager::GetLpInstance()->Fire(
						type, atkPos,
						motions[(int)state].mAtkInfo[frame].width,
						motions[(int)state].mAtkInfo[frame].height,
						5, 0,
						motions[(int)state].mAtkInfo[frame].imageKey,
						motions[(int)state].mAtkInfo[frame].hitEffectKey,
						10);
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

void Character::Stay()
{
	switch (state)
	{
	case Character::CHARACTER_STATE::MOVE:
	case Character::CHARACTER_STATE::MOVE_GUARD:
	case Character::CHARACTER_STATE::GUARD:
		elapsedTime = 0;
		frame = 0;
		priority = -1;
		state = CHARACTER_STATE::IDLE;
		break;
	}
}

void Character::Hit(int damage)
{
	if (IsAlive())
	{
		elapsedTime = 0;
		frame = 0;
	}
	priority = 10;

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
	priority = 10;
	state = CHARACTER_STATE::GUARD;
}

void Character::LeftMove(int priority)
{
	switch (state)
	{
	case Character::CHARACTER_STATE::IDLE:
	case Character::CHARACTER_STATE::MOVE:
	case Character::CHARACTER_STATE::MOVE_GUARD:
		pos.x -= moveSpeed;
		this->priority = priority;
		if (pos.x < 0) pos.x = 0;
		if (dir == DIRECTION::RIGHT) state = CHARACTER_STATE::MOVE_GUARD;
		else state = CHARACTER_STATE::MOVE;
		break;
	}
}

void Character::RightMove(int priority)
{
	switch (state)
	{
	case Character::CHARACTER_STATE::IDLE:
	case Character::CHARACTER_STATE::MOVE:
	case Character::CHARACTER_STATE::MOVE_GUARD:
		pos.x += moveSpeed;
		this->priority = priority;
		if (pos.x > WINSIZE_WIDTH) pos.x = WINSIZE_WIDTH;
		if (dir == DIRECTION::LEFT) state = CHARACTER_STATE::MOVE_GUARD;
		else state = CHARACTER_STATE::MOVE;
		break;
	}
}

void Character::WeakAttack(int priority)
{
	if (this->priority < priority)
	{
		frame = 0;
		elapsedTime = 0;
		this->priority = priority;
		state = CHARACTER_STATE::ATTACK_WEAK;
	}
}

void Character::StrongAttack(int priority)
{
	if (this->priority < priority)
	{
		frame = 0;
		elapsedTime = 0;
		this->priority = priority;
		state = CHARACTER_STATE::ATTACK_STRONG;
	}
}

void Character::KickAttack(int priority)
{
	if (this->priority < priority)
	{
		frame = 0;
		elapsedTime = 0;
		this->priority = priority;
		state = CHARACTER_STATE::ATTACK_KICK;
	}
}

void Character::RangeAttack(int priority)
{
	if (this->priority < priority)
	{
		frame = 0;
		elapsedTime = 0;
		this->priority = priority;
		state = CHARACTER_STATE::ATTACK_RANGE;
	}
}

void Character::Translate(POINTFLOAT delta)
{
	if (dir == DIRECTION::LEFT)
	{
		pos.x -= delta.x;
		pos.y -= delta.y;
	}
	else
	{
		pos.x += delta.x;
		pos.y += delta.y;
	}
	motions[(int)state].hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}
