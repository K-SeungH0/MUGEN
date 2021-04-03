#include "Character.h"
#include "Image.h"

void Character::Init()
{
}

void Character::Release()
{
	// �̹��������� ������ ImageManager�� �ϰ������� ���ִ� �κ��̱⿡ ����� �ӽ�
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
			// ������ ��ġ�� ���� �ϴٸ� ����!
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
	// �ִϸ��̼� �÷���
}

void Character::NormalAttack()
{
	state = CHARACTER_STATE::ATTACK_WEAK;
	// �ִϸ��̼� �÷���
}

void Character::StrongAttack()
{
	state = CHARACTER_STATE::ATTACK_STRONG;
	// �ִϸ��̼� �÷���
}

void Character::RangeAttack()
{

}
