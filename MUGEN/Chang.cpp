#include "Chang.h"
#include "Image.h"

Chang::Chang()
{
}

Chang::~Chang()
{
}

void Chang::Init()
{

	dir = DIRECTION::LEFT;
	state = CHARACTER_STATE::IDLE;
	hp = 100;
	preHp = 100;
	pos = { -300,  300 };
	name = "Chang Koehan";
	motions[(int)CHARACTER_STATE::IDLE].offsetPos = { 100,100 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = new Image();
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/Chang/LeftChang_Idle.bmp", 3960, 532, 6, 1, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/Chang/RightChang_Idle.bmp", 3960, 532, 6, 1, true, RGB(255, 0, 255));
	
	
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = new Image();
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/Chang/LeftChang_Move.bmp", 6600, 531, 11, 1, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/Chang/RightChang_Move.bmp", 6600, 531, 10, 1, true, RGB(255, 0, 255));
	
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT] = new Image();
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/Chang/LeftChang_RightPunch.bmp", 7920, 531, 12, 1, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/Chang/RightChang_RightPunch.bmp", 7920, 531, 12, 1, true, RGB(255, 0, 255));
	
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::RIGHT] = new Image();
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/Chang/LeftChang_LeftPunch.bmp", 3300, 532, 5, 1, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/Chang/RightChang_LeftPunch.bmp", 3300, 532, 5, 1, true, RGB(255, 0, 255));

	frame = 0;
	elapsedTime = 0;

}

void Chang::Release()
{
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT]->Release();
}

void Chang::Update()
{
	
	if ((int)state != 2 && (int)state != 3)
	{
		state = CHARACTER_STATE::IDLE;
		if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_LEFT))
		{
			dir = DIRECTION::LEFT;
			state = CHARACTER_STATE::MOVE;
			pos.x -= 5;
		}
		if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_RIGHT))
		{
			dir = DIRECTION::RIGHT;
			state = CHARACTER_STATE::MOVE;
			pos.x += 5;
		}
		if (KeyManager::GetLpInstance()->IsOnceKeyDown('X'))
		{
			frame = 0;
			state = CHARACTER_STATE::ATTACK_STRONG;
		}
		if (KeyManager::GetLpInstance()->IsOnceKeyDown('Z'))
		{
			frame = 0;
			state = CHARACTER_STATE::ATTACK_WEAK;
		}
	}

	if (elapsedTime++ % 10 == 0)
	{
		if ((int)state == 3 && frame != 11)
		{
			++frame;
		}
		else if ((int)state == 3)
		{
			state = CHARACTER_STATE::IDLE;
		}
		if ((int)state == 2 && frame != 4)
		{
			++frame;
		}
		else if ((int)state == 2)
		{
			state = CHARACTER_STATE::IDLE;
		}
		if ((int)state == 1)
		{
			++frame %= 10;
		}
		if ((int)state == 0)
		{
			++frame %= 5;
		}
	}

}



void Chang::Render(HDC hdc)
{
	if (motions[(int)state].lpImages[(int)dir]) motions[(int)state].lpImages[(int)dir]->Render(hdc, pos.x, pos.y - 200, frame);
}
