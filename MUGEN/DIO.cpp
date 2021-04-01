#include "DIO.h"
#include "Image.h"

DIO::DIO()
{
}

DIO::~DIO()
{
}

void DIO::Init()
{
	// 바라보는 방향
	dir = DIRECTION::LEFT;
	// 캐릭터 상태
	state = CHARACTER_STATE::MOVE;
	// 캐릭터 체력
	hp = 100;
	preHp = 100;
	// 캐릭터 위치
	pos = { 100, WINSIZE_HEIGHT - 100 };
	// 캐릭터 이름
	// /Image/Character/캐릭터이름/*.bmp
	string name = "DIO";
	// Init 모션별 초기화
	// IDLE
	motions[(int)CHARACTER_STATE::IDLE].offsetPos = { -33, -120 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = new Image();
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/DIO/DIO_RIGHT_IDLE.bmp", 198, 240, 3, 2, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/DIO/DIO_LEFT_IDLE.bmp", 198, 240, 3, 2, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetPos, 66, 120);
	// MOVE
	motions[(int)CHARACTER_STATE::MOVE].offsetPos = { -40, -120 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = new Image();
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/DIO/DIO_RIGHT_MOVE.bmp", 316, 464, 4, 4, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = new Image();
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/DIO/DIO_LEFT_MOVE.bmp", 316, 460, 4, 4, true, RGB(255, 0, 255));
	motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetPos, 79, 115);

	elapsedTime = 0;
	frame = 0;
}

void DIO::Release()
{
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT]->Release();
}

void DIO::Update()
{
	state = CHARACTER_STATE::IDLE;
	if (KeyManager::GetLpInstance()->IsStayKeyDown('A'))
	{
		dir = DIRECTION::LEFT;
		state = CHARACTER_STATE::MOVE;
		pos.x -= 10;
	}
	if (KeyManager::GetLpInstance()->IsStayKeyDown('D'))
	{
		dir = DIRECTION::RIGHT;
		state = CHARACTER_STATE::MOVE;
		pos.x += 10;
	}


	if (elapsedTime++ % 10 == 0)
	{
		++frame %= 6;
	}

	motions[(int)state].hitRc = GetRectOffset(pos, motions[(int)state].offsetPos, 79, 115);
}

void DIO::Render(HDC hdc)
{
	if (isDebugMode)
	{
		RECT rc;
		Rectangle(hdc, motions[(int)state].hitRc.left, motions[(int)state].hitRc.top, motions[(int)state].hitRc.right, motions[(int)state].hitRc.bottom);
	}

	POINTFLOAT drawPos = { pos.x + motions[(int)state].offsetPos.x, pos.y + motions[(int)state].offsetPos.y };
	if (motions[(int)state].lpImages[(int)dir]) motions[(int)state].lpImages[(int)dir]->Render(hdc, drawPos.x, drawPos.y, frame);
}
