#include "Character.h"
#include "Image.h"

void Character::Init()
{
}

void Character::Release()
{
	// 이미지에대한 해제는 ImageManager가 일괄적으로 해주는 부분이기에 현재는 임시
	//for (int i = 0; i < (int)DIRECTION::NONE; ++i)
	//{
	//	for (int k = 0; k < (int)CHARACTER_STATE::NONE; ++k)
	//	{
	//		if (motions[k].lpImages[i])
	//		{
	//			motions[k].lpImages[i]->Release();
	//			delete[] motions[k].lpImages;
	//		}
	//	}
	//}
}

void Character::Update()
{
	if (elapsedTime++ % 10 == 0)
	{
		++frame %= 6;

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

	POINTFLOAT drawPos;
	switch (dir)
	{
	case Character::DIRECTION::RIGHT:
		drawPos = { pos.x + motions[(int)state].offsetDrawPos.x, pos.y + motions[(int)state].offsetDrawPos.y };
		break;
	case Character::DIRECTION::LEFT:
		drawPos = { pos.x - motions[(int)state].offsetDrawPos.x, pos.y - motions[(int)state].offsetDrawPos.y };
		break;
	}
	if (motions[(int)state].lpImages[(int)dir]) motions[(int)state].lpImages[(int)dir]->Render(hdc, drawPos.x, drawPos.y, frame);
}

void Character::Hit(int damage)
{
	hp -= 0;
	if (hp < 0) hp = 0;
}

void Character::Move(DIRECTION direction)
{
	dir = direction;
	switch (direction)
	{
	case Character::DIRECTION::RIGHT:
		pos.x += moveSpeed;
		break;
	case Character::DIRECTION::LEFT:
		pos.x -= moveSpeed;
		break;
	}
	state = CHARACTER_STATE::MOVE;
	// 애니메이션 플레이
}

void Character::LeftMove()
{
	pos.x -= moveSpeed;
	state = CHARACTER_STATE::MOVE;
}

void Character::RightMove()
{
	pos.x += moveSpeed;
	state = CHARACTER_STATE::MOVE;
}

void Character::NormalAttack()
{
	state = CHARACTER_STATE::ATTACK_NORMAL;
	// 애니메이션 플레이


}

void Character::StrongAttack()
{
	state = CHARACTER_STATE::ATTACK_STRONG;
	// 애니메이션 플레이

	//MessageBox(g_hWnd, "강한 공격 커멘드 입력", "커멘드", MB_OK);
}

void Character::RangeAttack()
{
	state = CHARACTER_STATE::ATTACK_RANGE;
	// 애니메이션 플레이

}
