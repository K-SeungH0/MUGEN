#pragma once
#include "Mugen.h"
#include "GameObject.h"

class Image;
class Character : public GameObject
{
public:
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
		MOVE_GUARD,
		ATTACK_WEAK,
		ATTACK_NORMAL,
		ATTACK_STRONG,
		ATTACK_RANGE,
		HIT,
		DEATH,
		NONE
	};

protected:
	enum class ATTACK_TYPE
	{
		MELEE,
		RANGE,
		NONE
	};

	struct AttackInfo
	{
		ATTACK_TYPE type;
		// ������ġ(����)
		// �������� �ٶ󺸴� �������� ����
		POINTFLOAT offsetPos;
		int width;
		int height;
		// ������
		int damage;
	};
	struct MotionInfo
	{
		// ����� �̹����� �����ġ �׻� �������� �ٶ󺸴� �������� �����Ѵ�.
		// IMAGE RENDER StartX = pos.x + offsetDrawPos.x
		POINTFLOAT offsetDrawPos;
		// �̹���
		Image* lpImages[(int)DIRECTION::NONE];

		// ��Ʈ�ڽ� ����
		POINTFLOAT offsetHitPos;
		int width;
		int height;
		// ���� �ǰ� ����
		RECT hitRc;

		// ������, ��Ʈ����/������
		map<int, AttackInfo> mAtkInfo;
	};

	// �ִϸ��̼� ó���� ���� ����
	int elapsedTime;
	int frame;

	PLAYER_TYPE type = PLAYER_TYPE::NONE;
	// �ٶ󺸴� ����
	DIRECTION dir;
	// ĳ���� ����
	CHARACTER_STATE state;
	// ĳ���� ü��
	int hp;
	// ĳ���� ���ǵ�
	int moveSpeed;
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
	void Move(DIRECTION direction);
	void LeftMove();
	void RightMove();
	void NormalAttack();
	void StrongAttack();
	void RangeAttack();

	inline void SetType(PLAYER_TYPE type) { this->type = type; }
	inline bool IsAlive() { return state != CHARACTER_STATE::DEATH; }
	inline int GetHp() { return hp; }
};

