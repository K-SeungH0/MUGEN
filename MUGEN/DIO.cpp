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
	name = "DIO";
	// Init ��Ǻ� �ʱ�ȭ
	// IDLE
	motions[(int)CHARACTER_STATE::IDLE].offsetPos = { -33, -120 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_IDLE", 0);
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_IDLE", 0);
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetPos, 66, 120);
	// MOVE
	motions[(int)CHARACTER_STATE::MOVE].offsetPos = { -40, -120 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_MOVE", 0);
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_MOVE", 0);
	motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetPos, 79, 115);

	// �ӽ�
	motions[(int)CHARACTER_STATE::MOVE].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {40,-100}, 50, 100, 10 }));
	motions[(int)CHARACTER_STATE::MOVE].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {40,-100}, 50, 100, 10 }));
	motions[(int)CHARACTER_STATE::MOVE].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::RANGE, {40,-40}, 40, 40, 10 }));

	// ATTACK_STRONG
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetPos = { -40, -120 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_ATTACK_STRONG", 0);
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_ATTACK_STRONG", 0);
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetPos, 79, 115);

	elapsedTime = 0;
	frame = 0;

	moveSpeed = 5;
}