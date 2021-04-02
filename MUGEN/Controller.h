#pragma once
#include "GameObject.h"

class Character;
class Controller : public GameObject
{
public:
	enum class COMMAND_KIND
	{
		RANGE,
		NONE
	};

	struct Command
	{
		COMMAND_KIND kind;
	};

private:
	PLAYER_TYPE type;
	int elapsedTime;
	Character* lpCharacter;
	vector<int> command;

public:
	Controller();
	~Controller();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetController(PLAYER_TYPE type, Character* lpCharacter);
};

