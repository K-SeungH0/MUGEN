#include "King.h"
#include "Image.h"
void King::Init()
{
	//state = CHARACTER_STATE::IDLE;
	//if (FAILED(motions[(int)CHARACTER_STATE::IDLE].lpImages[0]->Init("Image/Character/King/Idle/King_Idle.bmp", 640, 112, 10, 1, true, RGB(140, 206, 156))))
	//{
	//
	//}
}

void King::Release()
{

}

void King::Update()
{

}

void King::Render(HDC hdc)
{
	if (motions[(int)state].lpImages[0]) motions[(int)state].lpImages[0]->Render(hdc, 100, 100);
}
