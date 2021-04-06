#pragma once

#include "Mugen.h"
#include "GameObject.h"

class GameScene : public GameObject
{
public:

protected:

public:
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

};

