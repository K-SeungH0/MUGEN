#pragma once
#include "Character.h"

class DIO : public Character
{
public:
	DIO();
	~DIO();

	virtual void Init() override;

	virtual void FinalAttack(int priority) override;
};