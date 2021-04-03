#pragma once
#include "Character.h"
class King : public Character
{
public:
	King();
	~King();

	void Init() final;
};