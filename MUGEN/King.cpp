#include "King.h"
#include "Image.h"

void King::Init()
{
	dir = DIRECTION::LEFT;
	state = CHARACTER_STATE::IDLE;

	elapsedTime = 0;
	frame = 0;

	hp = 100;

	pos = { WINSIZE_WIDTH / 2, WINSIZE_HEIGHT / 2};

	name = "KING";
	lpImage = new Image();
	auto del_RGB = RGB(140, 206, 156);
}

void King::Release()
{
	//motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT]->Release();
	lpImage->Release();
}

void King::Update()
{
	switch (state)
	{
	case Character::CHARACTER_STATE::IDLE:
		if(dir == Character::DIRECTION::LEFT)
			lpImage = ImageManager::GetLpInstance()->Play("KING_LEFT_SKILL", frame);
		else
			lpImage = ImageManager::GetLpInstance()->Play("KING_RIGHT_IDLE", frame);
		break;
	case Character::CHARACTER_STATE::MOVE:
		if (dir == Character::DIRECTION::LEFT)
			lpImage = ImageManager::GetLpInstance()->Play("KING_LEFT_MOVE", frame);
		else
			lpImage = ImageManager::GetLpInstance()->Play("KING_RIGHT_MOVE", frame);
		break;
	case Character::CHARACTER_STATE::ATTACK_WEAK:
		break;
	case Character::CHARACTER_STATE::ATTACK_STRONG:
		break;
	case Character::CHARACTER_STATE::HIT:
		break;
	case Character::CHARACTER_STATE::DEATH:
		break;
	case Character::CHARACTER_STATE::NONE:
		break;
	}

	if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_LEFT))
	{
		dir = DIRECTION::LEFT;
		state = CHARACTER_STATE::MOVE;
		pos.x -= 2;
	}
	else if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_RIGHT))
	{
		dir = DIRECTION::LEFT;
		state = CHARACTER_STATE::MOVE;
		pos.x += 2;
	}
	else
	{
		dir = DIRECTION::LEFT;
		state = CHARACTER_STATE::IDLE;
	}

	if (elapsedTime++ % 10 == 0)
	{
		++frame %= lpImage->GetImageInfo()->maxFrameX;
	}
}

void King::Render(HDC hdc)
{
	lpImage->Render(hdc, pos.x, pos.y);
}
