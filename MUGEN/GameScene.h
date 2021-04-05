#pragma once

#include "Mugen.h"
#include "GameObject.h"

class GameScene
{
public:

	enum class game_Background_type
	{
		INGAME,
		SELECT,
		NONE
	};
	;


protected:
	int elapsedTime;
	game_Background_type Background;

public:

};

