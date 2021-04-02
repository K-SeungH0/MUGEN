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

		switch (state)
		{
		case Character::CHARACTER_STATE::MOVE:
			if (frame == 3)
			{
				ColliderManager::GetLpInstance()->Fire(type, pos, 50, 50, 5, 0);
				//ColliderManager::GetLpInstance()->Create(type, pos, 400, 400);
			}
			break;
		case Character::CHARACTER_STATE::ATTACK_WEAK:
			break;
		case Character::CHARACTER_STATE::ATTACK_STRONG:
			break;
		case Character::CHARACTER_STATE::HIT:
			break;
		case Character::CHARACTER_STATE::DEATH:
			break;
		}
	}

	motions[(int)state].hitRc = GetRectOffset(pos, motions[(int)state].offsetPos, 79, 115);
}

void Character::Render(HDC hdc)
{
	if (isDebugMode)
	{
		RECT rc;
		Rectangle(hdc, motions[(int)state].hitRc.left, motions[(int)state].hitRc.top, motions[(int)state].hitRc.right, motions[(int)state].hitRc.bottom);
	}

	POINTFLOAT drawPos = { pos.x + motions[(int)state].offsetPos.x, pos.y + motions[(int)state].offsetPos.y };
	if (motions[(int)state].lpImages[(int)dir]) motions[(int)state].lpImages[(int)dir]->Render(hdc, drawPos.x, drawPos.y, frame);
}

void Character::Hit(int damage)
{
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
}

void Character::NormalAttack()
{
	state = CHARACTER_STATE::ATTACK_WEAK;
}

void Character::StrongAttack()
{
	state = CHARACTER_STATE::ATTACK_STRONG;
}
