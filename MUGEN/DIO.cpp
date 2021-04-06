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
	// �ٶ󺸴� ����
	dir = CHARACTER_DIRECTION::RIGHT;
	// ĳ���� ����
	state = CHARACTER_STATE::IDLE;
	// ĳ���� ü��
	hp = 100;
	// ĳ���� ��ġ
	pos = { 0, 0 };
	// ĳ���� �̸�
	// /Image/Character/ĳ�����̸�/*.bmp
	name = "DIO";
	elapsedTime = 0;
	frame = 0;
	moveSpeed = 5;

	// Init ��Ǻ� �ʱ�ȭ
	LoadData();

	lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
	hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}