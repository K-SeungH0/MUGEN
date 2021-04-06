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

		if (motions[(int)state].mAtkInfos.find(frame) != motions[(int)state].mAtkInfos.end())
		{
			// 공격할 위치가 존재 하다면 공격!
			POINTFLOAT atkPos;
			switch (motions[(int)state].mAtkInfos[frame][0].type)
			{
			case ATTACK_TYPE::MELEE:
				if (dir == CHARACTER_DIRECTION::LEFT) atkPos = { pos.x - motions[(int)state].mAtkInfos[frame][0].offsetPos.x, pos.y + motions[(int)state].mAtkInfos[frame][0].offsetPos.y };
				else atkPos = { pos.x + motions[(int)state].mAtkInfos[frame][0].offsetPos.x, pos.y + motions[(int)state].mAtkInfos[frame][0].offsetPos.y };
				ColliderManager::GetLpInstance()->Create(type, atkPos,
													motions[(int)state].mAtkInfos[frame][0].width,
													motions[(int)state].mAtkInfos[frame][0].height,
													motions[(int)state].mAtkInfos[frame][0].hitEffectKey[(int)dir],
													10);
				break;
			case ATTACK_TYPE::RANGE:
				if (dir == CHARACTER_DIRECTION::LEFT)
				{
					atkPos = { pos.x - motions[(int)state].mAtkInfos[frame][0].offsetPos.x, pos.y + motions[(int)state].mAtkInfos[frame][0].offsetPos.y };
					ColliderManager::GetLpInstance()->Fire(
									type, atkPos, 
									motions[(int)state].mAtkInfos[frame][0].width,
									motions[(int)state].mAtkInfos[frame][0].height,
									5, PI,
									motions[(int)state].mAtkInfos[frame][0].imageKey[(int)dir],
									motions[(int)state].mAtkInfos[frame][0].hitEffectKey[(int)dir],
									10);
				}
				else
				{
					atkPos = { pos.x + motions[(int)state].mAtkInfos[frame][0].offsetPos.x, pos.y + motions[(int)state].mAtkInfos[frame][0].offsetPos.y };
					ColliderManager::GetLpInstance()->Fire(
						type, atkPos,
						motions[(int)state].mAtkInfos[frame][0].width,
						motions[(int)state].mAtkInfos[frame][0].height,
						5, 0,
						motions[(int)state].mAtkInfos[frame][0].imageKey[(int)dir],
						motions[(int)state].mAtkInfos[frame][0].hitEffectKey[(int)dir],
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

void Character::LoadData()
{
	// INI파일 로드
	if (FileManager::GetLpInstance()->ReadFile("INI/" + name + ".ini"))
	{
		int state;
		string group;
		vector<float> vFloats;
		for (int i = 0; i < (int)CHARACTER_STATE::NONE; ++i)
		{
			group = GetKey("", CHARACTER_DIRECTION::NONE, (CHARACTER_STATE)i);

			state = FileManager::GetLpInstance()->GetData<int>(group, "CHARACTER_STATE");
			vFloats = FileManager::GetLpInstance()->GetData<vector<float>>(group, "OFFSET_DRAW_POS");
			for (int k = 0; k < vFloats.size(); ++k)
			{
				if (k % 2 == 0) motions[state].offsetDrawPos[k / 2].x = vFloats[k];
				else motions[state].offsetDrawPos[k / 2].y = vFloats[k];
			}
			vFloats = FileManager::GetLpInstance()->GetData<vector<float>>(group, "OFFSET_HIT_POS");
			for (int k = 0; k < vFloats.size(); ++k)
			{
				if (k % 2 == 0) motions[state].offsetHitPos.x = vFloats[k];
				else motions[state].offsetHitPos.y = vFloats[k];
			}
			motions[state].width = FileManager::GetLpInstance()->GetData<int>(group, "HIT_RECT_WIDTH");
			motions[state].height = FileManager::GetLpInstance()->GetData<int>(group, "HIT_RECT_HEIGHT");
			motions[state].motionSpeed = FileManager::GetLpInstance()->GetData<int>(group, "MOTION_SPEED");
		}
	}
	else
	{
		MessageBox(g_hWnd, "캐릭터 INI파일을 읽지 못하였습니다.", "Error", MB_OK);
	}

	if (FileManager::GetLpInstance()->ReadFile("INI/" + name + "_ATTACKINFO.ini"))
	{
		int state;
		string group;
		vector<int> vFrames;
		vector<int> vAtkTypes;
		vector<float> vOffsetPos;
		vector<int> vHitRectWidths;
		vector<int> vHitRectHeights;
		vector<int> vDamages;
		vector<string> vImageKeys;
		vector<string> vEffectKeys;
		AttackInfo atkInfo;
		map<int, vector<AttackInfo>>* lpmAtkInfo = nullptr;
		for (int i = 0; i < (int)CHARACTER_STATE::NONE; ++i)
		{
			group = GetKey("", CHARACTER_DIRECTION::NONE, (CHARACTER_STATE)i);
			state = FileManager::GetLpInstance()->GetData<int>(group, "CHARACTER_STATE");
			lpmAtkInfo = &motions[state].mAtkInfos;
			vFrames = FileManager::GetLpInstance()->GetData<vector<int>>(group, "FRAME");
			vAtkTypes = FileManager::GetLpInstance()->GetData<vector<int>>(group, "ATTACK_TYPE");
			vOffsetPos = FileManager::GetLpInstance()->GetData<vector<float>>(group, "OFFSET_POS");
			vHitRectWidths = FileManager::GetLpInstance()->GetData<vector<int>>(group, "HIT_RECT_WIDTH");
			vHitRectHeights = FileManager::GetLpInstance()->GetData<vector<int>>(group, "HIT_RECT_HEIGHT");
			vDamages = FileManager::GetLpInstance()->GetData<vector<int>>(group, "DAMAGE");
			vImageKeys = FileManager::GetLpInstance()->GetData<vector<string>>(group, "IMAGE_KEY");
			vEffectKeys = FileManager::GetLpInstance()->GetData<vector<string>>(group, "EFFECT_KEY");
			for (int k = 0; k < vFrames.size(); ++k)
			{
				atkInfo.type = (ATTACK_TYPE)vAtkTypes[k];
				atkInfo.offsetPos = { vOffsetPos[k * 2], vOffsetPos[k * 2 + 1] };
				atkInfo.damage = vDamages[k];
				atkInfo.height = vHitRectHeights[k];
				atkInfo.width = vHitRectWidths[k];
				if (vImageKeys[k][0] != '-')
				{
					atkInfo.imageKey[0] = GetKey(name, CHARACTER_DIRECTION::RIGHT, (CHARACTER_STATE)state, vImageKeys[k]);
					atkInfo.imageKey[0] = GetKey(name, CHARACTER_DIRECTION::LEFT, (CHARACTER_STATE)state, vImageKeys[k]);
				}
				if (vEffectKeys[k][0] != '-')
				{
					atkInfo.hitEffectKey[0] = GetKey(name, CHARACTER_DIRECTION::RIGHT, (CHARACTER_STATE)state, vEffectKeys[k]);
					atkInfo.hitEffectKey[0] = GetKey(name, CHARACTER_DIRECTION::LEFT, (CHARACTER_STATE)state, vEffectKeys[k]);
				}
				if (lpmAtkInfo->find(vFrames[k]) == lpmAtkInfo->end())
				{
					lpmAtkInfo->insert(make_pair(vFrames[k], vector<AttackInfo>{atkInfo}));
				}
				else
				{
					(*lpmAtkInfo)[vFrames[k]].push_back(atkInfo);
				}
			}
		}
	}
	else
	{
		MessageBox(g_hWnd, "캐릭터 공격정보 INI파일을 읽지 못하였습니다.", "Error", MB_OK);
	}
}
