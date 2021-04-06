#pragma once
#include "GameObject.h"

class Character;
class Controller : public GameObject
{
public:
	enum class SKILL_KIND
	{
		LEFT,
		RIGHT,
		DOWN,
		UP,
		ATTACK_WEAK,
		ATTACK_STRONG,
		ATTACK_KICK,
		ATTACK_RANGE,
		NONE
	};

	struct Skill
	{
		int priority;
		function<void(Character&, int)> lpfnCmd = nullptr;
	};

	struct Command
	{
		Skill* skill = nullptr;
		map<SKILL_KIND, Command> mCombo;
	};

private:
	PLAYER_TYPE type = PLAYER_TYPE::NONE;
	int elapsedTime = 0;
	Character* lpCharacter =  nullptr;

	map<SKILL_KIND, Command>* lpmCommands = nullptr;

	// ĳ���� ���
	Skill skills[(int)SKILL_KIND::NONE];

	// ĳ���� Ŀ�ǵ�
	map<SKILL_KIND, Command> mCommands;

	// Key Map
	map<SKILL_KIND, int> mSkillKey;

public:
	Controller();
	~Controller();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetController(PLAYER_TYPE type, Character* lpCharacter);

	inline PLAYER_TYPE GetPlayerType() { return type; }
	inline Character* GetLpCharacter() { return lpCharacter; }
private:
	void CommandInput(SKILL_KIND kind);
};