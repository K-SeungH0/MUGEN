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
		if (frame + 1 == lpImage->GetImageInfo()->maxFrame) return;
	}

	if (++elapsedTime % motions[(int)state].motionSpeed == 0)
	{
		++frame %= lpImage->GetImageInfo()->maxFrame;
		if (frame == 0)
		{
			// 모션이 한사이클 끝남
			switch (state)
			{
			case CHARACTER_STATE::GUARD:
				state = CHARACTER_STATE::MOVE_GUARD;
				priority = -1;
				lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
				break;
			case CHARACTER_STATE::ATTACK_WEAK:
			case CHARACTER_STATE::ATTACK_STRONG:
			case CHARACTER_STATE::ATTACK_KICK:
			case CHARACTER_STATE::ATTACK_RANGE:
			case CHARACTER_STATE::HIT:
				state = CHARACTER_STATE::IDLE;
				priority = -1;
				lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
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
				if (dir == CHARACTER_DIRECTION::LEFT) atkPos = { pos.x - motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
				else atkPos = { pos.x + motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
				ColliderManager::GetLpInstance()->Create(type, atkPos,
													motions[(int)state].mAtkInfo[frame].width,
													motions[(int)state].mAtkInfo[frame].height,
													motions[(int)state].mAtkInfo[frame].hitEffectKey,
													10);
				break;
			case ATTACK_TYPE::RANGE:
				if (dir == CHARACTER_DIRECTION::LEFT)
				{
					atkPos = { pos.x - motions[(int)state].mAtkInfo[frame].offsetPos.x, pos.y + motions[(int)state].mAtkInfo[frame].offsetPos.y };
					ColliderManager::GetLpInstance()->Fire(
									type, atkPos, 
									motions[(int)state].mAtkInfo[frame].width,
									motions[(int)state].mAtkInfo[frame].height,
									5, PI,
									motions[(int)state].mAtkInfo[frame].imageKey[(int)dir],
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
						motions[(int)state].mAtkInfo[frame].imageKey[(int)dir],
						motions[(int)state].mAtkInfo[frame].hitEffectKey,
						10);
				}
				break;
			}
		}
	}

	motions[(int)state].hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);

	hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}

void Character::Render(HDC hdc)
{
	if (isDebugMode)
	{
		RECT rc;
		Rectangle(hdc, hitRc.left, hitRc.top, hitRc.right, hitRc.bottom);

		Ellipse(hdc, pos.x - 10, pos.y - 10, pos.x + 10, pos.y + 10);
	}

	POINTFLOAT drawPos = { pos.x + motions[(int)state].offsetDrawPos[(int)dir].x, pos.y + motions[(int)state].offsetDrawPos[(int)dir].y };
	if (lpImage) lpImage->Render(hdc, drawPos.x, drawPos.y, frame);
}

void Character::Stay()
{
	switch (state)
	{
	case CHARACTER_STATE::MOVE:
	case CHARACTER_STATE::MOVE_GUARD:
	case CHARACTER_STATE::GUARD:
		elapsedTime = 0;
		frame = 0;
		priority = -1;
		state = CHARACTER_STATE::IDLE;
		lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
		break;
	}
}

void Character::Hit(int damage, POINTFLOAT hitPoint, string hitEffectKey)
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

	if (state != CHARACTER_STATE::GUARD)
	{
		hp -= damage;
		EffectManager::GetLpInstance()->EffectRender(hitPoint, hitEffectKey);
	}
	else
	{
		damage *= 0.1f;
		if (damage <= 0) damage = 1;
		hp -= damage;
		EffectManager::GetLpInstance()->EffectRender(hitPoint, "EFFECT_GUARD");
	}
	
	if (hp <= 0)
	{
		hp = 0;
		state = CHARACTER_STATE::DEATH;
	}
	lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
}

void Character::Guard()
{
	frame = 0;
	elapsedTime = 0;
	priority = 10;
	state = CHARACTER_STATE::GUARD;
	lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
}

void Character::LeftMove(int priority)
{
	switch (state)
	{
	case CHARACTER_STATE::IDLE:
	case CHARACTER_STATE::MOVE:
	case CHARACTER_STATE::MOVE_GUARD:
		pos.x -= moveSpeed;
		this->priority = priority;
		if (pos.x < 0) pos.x = 0;
		if (dir == CHARACTER_DIRECTION::RIGHT) state = CHARACTER_STATE::MOVE_GUARD;
		else state = CHARACTER_STATE::MOVE;
		lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
		break;
	}
}

void Character::RightMove(int priority)
{
	switch (state)
	{
	case CHARACTER_STATE::IDLE:
	case CHARACTER_STATE::MOVE:
	case CHARACTER_STATE::MOVE_GUARD:
		pos.x += moveSpeed;
		this->priority = priority;
		if (pos.x > WINSIZE_WIDTH) pos.x = WINSIZE_WIDTH;
		if (dir == CHARACTER_DIRECTION::LEFT) state = CHARACTER_STATE::MOVE_GUARD;
		else state = CHARACTER_STATE::MOVE;
		lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
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
		lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
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
		lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
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
		lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
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
		lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
	}
}

void Character::Translate(POINTFLOAT delta)
{
	if (dir == CHARACTER_DIRECTION::LEFT)
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
	hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}
