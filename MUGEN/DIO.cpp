#include "Mugen.h"
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

	// 임시
	motions[(int)CHARACTER_STATE::MOVE].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {40,-100}, 50, 100, 10 }));
	motions[(int)CHARACTER_STATE::MOVE].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {40,-100}, 50, 100, 10 }));
	motions[(int)CHARACTER_STATE::MOVE].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::RANGE, {40,-40}, 40, 40, 10 }));

	// ATTACK_STRONG
	//motions[(int)CHARACTER_STATE::MOVE].offsetPos = { -40, -120 };
	//motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = new Image();
	//motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT]->Init("Image/Character/DIO/DIO_RIGHT_MOVE.bmp", 316, 464, 4, 4, true, RGB(255, 0, 255));
	//motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = new Image();
	//motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT]->Init("Image/Character/DIO/DIO_LEFT_MOVE.bmp", 316, 460, 4, 4, true, RGB(255, 0, 255));
	//motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetPos, 79, 115);

	elapsedTime = 0;
	frame = 0;

	moveSpeed = 5;
}