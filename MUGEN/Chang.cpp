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
	state = CHARACTER_STATE::MOVE;
	hp = 100;
	preHp = 100;
	pos = { WINSIZE_WIDTH / 2, WINSIZE_HEIGHT - 200 };
	name = "Chang Koehan";
	motions[(int)CHARACTER_STATE::IDLE].offsetPos = { 100,100 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = new Image();
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/RightChang_IDLE.bmp", 3960, 532, 6, 1, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/LeftChang_IDLE.bmp", 3960, 532, 6, 1, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetPos, 66, 120);

	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = new Image();
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/RightChang_MOVE.bmp", 3960, 532, 10, 1, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/LeftChang_MOVE.bmp", 3960, 532, 10, 1, true, RGB(255, 0, 255));
	frame = 0;
	elapsedTime = 0;

}

void Chang::Release()
{
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT]->Release();
}

void Chang::Update()
{
	if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_LEFT))
	{
		dir = DIRECTION::LEFT;
		state = CHARACTER_STATE::MOVE;
		pos.x -= 10;
	}
	if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_RIGHT))
	{
		dir = DIRECTION::RIGHT;
		state = CHARACTER_STATE::MOVE;
		pos.x += 10;
	}


	if (elapsedTime++ % 10 == 0)
	{
		++frame %= 6;
	}


}


void Chang::Render(HDC hdc)
{
	motions[(int)CHARACTER_STATE::IDLE].lpImages[0]->Render(hdc, 100, 100);
}
