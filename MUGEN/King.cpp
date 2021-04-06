#include "Mugen.h"
#include "King.h"
#include "Image.h"
#include <fstream>

King::King()
{
}

King::~King()
{
}

void King::Init()
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
	name = "KING";
	elapsedTime = 0;
	frame = 0;
	moveSpeed = 5;

	LoadData();

	lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
	hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}