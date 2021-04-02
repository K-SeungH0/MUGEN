#include "King.h"
#include "Image.h"

void King::Init()
{
	dir = DIRECTION::LEFT;
	state = CHARACTER_STATE::IDLE;
	hp = 100;
	preHp = 100;
	pos = { WINSIZE_WIDTH / 2, WINSIZE_HEIGHT / 2};
	auto del_RGB = RGB(140, 206, 156);

	//Idle
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/KING/KING_Idle.bmp", 640, 112, 10, 1, true, del_RGB);
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetPos, 66, 120);
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/KING/KING_Idle.bmp", 640, 112, 10, 1, true, del_RGB);
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetPos, 66, 120);
}

void King::Release()
{
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT]->Release();
}

void King::Update()
{

}

void King::Render(HDC hdc)
{
	motions[(int)state].lpImages[(int)dir]->Render(hdc);
}
