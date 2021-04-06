#include "Mugen.h"
#include "DIO.h"
#include "Image.h"
#include <fstream>

DIO::DIO()
{
}

DIO::~DIO()
{
}

void DIO::Init()
{
	// 바라보는 방향
	dir = CHARACTER_DIRECTION::RIGHT;
	// 캐릭터 상태
	state = CHARACTER_STATE::IDLE;
	// 캐릭터 체력
	hp = 100;
	// 캐릭터 위치
	pos = { 0, 0 };
	// 캐릭터 이름
	// /Image/Character/캐릭터이름/*.bmp
	name = "DIO";
	elapsedTime = 0;
	frame = 0;
	moveSpeed = 5;

	// Init 모션별 초기화
	LoadData();

	lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
	hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}