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
	// �ٶ󺸴� ����
	dir = DIRECTION::LEFT;
	// ĳ���� ����
	state = CHARACTER_STATE::MOVE;
	// ĳ���� ü��
	hp = 100;
	// ĳ���� ��ġ
	pos = { 100, WINSIZE_HEIGHT - 100 };
	// ĳ���� �̸�
	// /Image/Character/ĳ�����̸�/*.bmp
	string name = "DIO";
	// Init ��Ǻ� �ʱ�ȭ
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

	// �ӽ�
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