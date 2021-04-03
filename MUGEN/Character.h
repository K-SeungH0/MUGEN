#pragma once
#include "Mugen.h"
#include "GameObject.h"

class Image;
class Character : public GameObject
{
protected:
	enum class DIRECTION
	{
		RIGHT,
		LEFT,
		NONE
	};
	enum class CHARACTER_STATE
	{
		IDLE,
		MOVE,
		ATTACK_WEAK,
		ATTACK_STRONG,
		HIT,
		DEATH,
		NONE
	};
	struct AttackInfo
	{
		// ��������
		RECT rc;
		// ������
		int damage;
	};

	struct MotionInfo
	{
		// ����� �̹����� �����ġ
		// IMAGE RENDER StartX = pos.x + offsetPos.x
		POINTFLOAT offsetPos;
		// �̹���
		Image* lpImages[(int)DIRECTION::NONE];
		// ���� �ǰ� ����
		RECT hitRc;
		// ������, ��Ʈ����/������
		map<int, AttackInfo> mAtkInfo;
	};


	// �ٶ󺸴� ����
	DIRECTION dir;
	// ĳ���� ����
	CHARACTER_STATE state;
	int elapsedTime;
	int frame;
	// ĳ���� ü��
	int hp;
	int preHp;
	// ĳ���� ��ġ
	POINTFLOAT pos;
	// ĳ���� �̸�
	// /Image/Character/ĳ�����̸�/*.bmp
	string name;

	// Render�� image
	Image* lpImage;

	// Init ��Ǻ� �ʱ�ȭ
	MotionInfo motions[(int)CHARACTER_STATE::NONE];

public:
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Hit(int damage);

	inline bool IsAlive() { return state != CHARACTER_STATE::DEATH; }
};

