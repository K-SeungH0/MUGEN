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
		ATTACK_NORMAL,
		ATTACK_STRONG,
		ATTACK_RANGE,
		NONE
	};

	struct Skill
	{
		function<void(Character&)> lpfnCmd = nullptr;
	};

	struct Command
	{
		Skill* skill = nullptr;
		map<SKILL_KIND, Command> mCombo;
	};

private:
	PLAYER_TYPE type;
	int elapsedTime;
	Character* lpCharacter;

	map<SKILL_KIND, Command>* lpmCommands = nullptr;

	// 캐릭터 기술
	Skill skills[(int)SKILL_KIND::NONE];

	// 캐릭터 커맨드
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

private:
	void CommandInput(SKILL_KIND kind);
};

