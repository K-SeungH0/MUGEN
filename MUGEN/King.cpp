#include "King.h"
#include "Image.h"
void King::Init()
{
	this->motions[0] = MotionInfo();
	this->motions[0].offsetPos = { 0.0f, 0.0f };
	this->motions[0].lpImages[0] = new Image();

	if (FAILED(motions[(int)CHARACTER_STATE::IDLE].lpImages[0]->Init("Image/Character/King/Idle/King_Idle.bmp", 640, 112, 10, 1, true, RGB(140, 206, 156))))
	{

	}
}

void King::Release()
{

}

void King::Update()
{

}

void King::Render(HDC hdc)
{
	motions[(int)CHARACTER_STATE::IDLE].lpImages[0]->Render(hdc, 100, 100);
}
