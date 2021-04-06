#pragma once
#include "Mugen.h"
#include "GameObject.h"

class GameUI : public GameObject 
{

public:
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};

