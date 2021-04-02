#pragma once
#include "Character.h"
class DIO : public Character
{
public:
	DIO();
	~DIO();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};

