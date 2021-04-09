#pragma once
#include "GameUI.h"

class Character;
class UInGameHpBar : public GameUI
{
private:
	int progress;
	Character* target;

};

