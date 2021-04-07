#pragma once
#include "Mugen.h"
#include "GameObject.h"

class Image;
class Character : public GameObject
{
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

		// ���ݽ� ���� �̹��� ������
		string imageKey[(int)CHARACTER_DIRECTION::NONE];
		string hitEffectKey[(int)CHARACTER_DIRECTION::NONE];
	};
	struct MotionInfo
	{
		// ����� �̹����� �����ġ �׻� �������� �ٶ󺸴� �������� �����Ѵ�.
		// IMAGE RENDER StartX = pos.x + offsetDrawPos.x
		POINTFLOAT offsetDrawPos[(int)CHARACTER_DIRECTION::NONE];
		// �ִϸ��̼� �ӵ� Ŭ���� ���� 1 ~ 100
		int motionSpeed = 10;

		// ��Ʈ�ڽ� ����
		POINTFLOAT offsetHitPos;
		int width;
		int height;
		// ������, ��Ʈ����/������
		map<int, vector<AttackInfo>> mAtkInfos;
	};

protected:
	// �ִϸ��̼� ó���� ���� ����
	int elapsedTime;
	int frame;
	int priority;

	// ĳ������ Ÿ�� - 1P / 2P
	PLAYER_TYPE type = PLAYER_TYPE::NONE;
	// ĳ���Ͱ� �ٶ� ���� / ������ ����
	CHARACTER_DIRECTION dir;
	// ĳ���� ����
	CHARACTER_STATE state;
	// ĳ������ ���� ������ �̹���
	Image* lpImage;
	// ĳ������ ��Ʈ�ڽ�
	RECT hitRc;

	// ĳ���� ��ġ
	POINTFLOAT pos;
	// ĳ���� ü��
	int hp;
	// ĳ���� ���ǵ�
	int moveSpeed;

	// ĳ���� �̸�
	// /Image/Character/ĳ�����̸�/*.bmp
	string name;

	// ��Ǻ� ��������
	MotionInfo motions[(int)CHARACTER_STATE::NONE];

public:
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	// �ൿ
	void Stay();
	void Hit(int damage, POINTFLOAT hitPoint, string hitEffectKey);
	void Guard();

	// Ŀ�ǵ�
	void LeftMove(int priority);
	void RightMove(int priority);
	void WeakAttack(int priority);
	void StrongAttack(int priority);
	void KickAttack(int priority);
	void RangeAttack(int priority);

	// �ٶ󺸴� �������� �̵�
	void Translate(POINTFLOAT delta);

	inline void RefreshImage() { lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state)); }
	inline void SetPos(POINTFLOAT pos) { this->pos = pos; }
	inline void SetType(PLAYER_TYPE type) { this->type = type; }
	inline void SetDirection(CHARACTER_DIRECTION dir) { this->dir = dir; }
	inline bool IsAlive() { return state != CHARACTER_STATE::DEATH; }
	inline int GetHp() { return hp; }
	inline POINTFLOAT GetPos() { return pos; }
	inline RECT GetHitRect() { return hitRc; }
	inline PLAYER_TYPE GetPlayerType() { return type; }

protected:
	// INI���� �ε�
	void LoadData();
};

