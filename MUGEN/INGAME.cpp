#include "Ingame.h"
#include "Image.h"

InGame::InGame()
{
}

InGame::~InGame()
{
}

HRESULT InGame::Init()
{
	Player1_HPUI = ImageManager::GetLpInstance()->GetImage("Player1_HPUI");
	Player2_HPUI = ImageManager::GetLpInstance()->GetImage("Player2_HPUI");
	Player1_HP = ImageManager::GetLpInstance()->GetImage("HP");
	Player2_HP = ImageManager::GetLpInstance()->GetImage("HP");
	Player1_DelayHP = ImageManager::GetLpInstance()->GetImage("Delay_HP");
	Player2_DelayHP = ImageManager::GetLpInstance()->GetImage("Delay_HP");
	lpKOImg = ImageManager::GetLpInstance()->GetImage("KO");
	Time0 = ImageManager::GetLpInstance()->GetImage("TIME0");
	Time1 = ImageManager::GetLpInstance()->GetImage("TIME1");
	Time2 = ImageManager::GetLpInstance()->GetImage("TIME2");
	Time3 = ImageManager::GetLpInstance()->GetImage("TIME3");
	Time4 = ImageManager::GetLpInstance()->GetImage("TIME4");
	Time5 = ImageManager::GetLpInstance()->GetImage("TIME5");
	Time6 = ImageManager::GetLpInstance()->GetImage("TIME6");
	Time7 = ImageManager::GetLpInstance()->GetImage("TIME7");
	Time8 = ImageManager::GetLpInstance()->GetImage("TIME8");
	Time9 = ImageManager::GetLpInstance()->GetImage("TIME9");

	return S_OK;
}

void InGame::Release()
{
	Player1_HPUI->Release();
	Player2_HPUI->Release();
	Player1_HP->Release();
	Player2_HP->Release();
	Player1_DelayHP->Release();
	Player2_DelayHP->Release();
	lpKOImg->Release();
}

void InGame::Update()
{
	elapsedTime++;
	if (elapsedTime % 2 == 0)
	{
		if (frame != 33)
			frame++;
		else
			frame = 0;
	}
	if (elapsedTime % 70 == 0)
	{
		if(time !=0)
			time--;
	}
}

void InGame::Render(HDC hdc)
{
	POINTFLOAT Player1_HPUIPos = { 0,0 };
	if (Player1_HPUI)Player1_HPUI->Render(hdc, Player1_HPUIPos.x, Player1_HPUIPos.y);
	POINTFLOAT Player2_HPUIPos = { WINSIZE_WIDTH - 750,0 };
	if (Player2_HPUI)Player2_HPUI->Render(hdc, Player2_HPUIPos.x, Player2_HPUIPos.y);

	POINTFLOAT Player1_DelayHPPos = { 187,86 };
	if (Player1_DelayHP)Player1_DelayHP->Render(hdc, Player1_DelayHPPos.x, Player1_DelayHPPos.y);
	POINTFLOAT Player2_DelayHPPos = { WINSIZE_WIDTH - 695,86 };
	if (Player2_DelayHP)Player2_DelayHP->Render(hdc, Player2_DelayHPPos.x, Player2_DelayHPPos.y);

	POINTFLOAT Player1_HPPos = { 187,86 };
	if (Player1_HP)Player1_HP->Render(hdc, Player1_HPPos.x, Player1_HPPos.y);
	POINTFLOAT Player2_HPPos = { WINSIZE_WIDTH - 695,86 };
	if (Player2_HP)Player2_HP->Render(hdc, Player2_HPPos.x, Player2_HPPos.y);

	POINTFLOAT KOPos = { WINSIZE_WIDTH/2-250,WINSIZE_HEIGHT/2-144};
	if (lpKOImg)lpKOImg->Render(hdc, KOPos.x, KOPos.y, frame);

	if (0 == time / 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 100, 50 };
		if (Time0)Time0->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (1 == time / 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 100, 50 };
		if (Time1)Time1->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (2 == time / 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 100, 50 };
		if (Time2)Time2->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (3 == time / 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 100, 50 };
		if (Time3)Time3->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (4 == time / 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 100, 50 };
		if (Time4)Time4->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (5 == time / 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 100, 50 };
		if (Time5)Time5->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (6 == time / 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 100, 50 };
		if (Time6)Time6->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (0 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2, 50 };
		if (Time0)Time0->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (1 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 ,50 };
		if (Time1)Time1->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (2 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2, 50 };
		if (Time2)Time2->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (3 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2, 50 };
		if (Time3)Time3->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (4 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 ,50 };
		if (Time4)Time4->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (5 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2, 50 };
		if (Time5)Time5->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (6 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2, 50 };
		if (Time6)Time6->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (7 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2, 50 };
		if (Time7)Time7->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (8 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2, 50 };
		if (Time8)Time8->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
	if (9 == time % 10)
	{
		POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2, 50 };
		if (Time9)Time9->Render(hdc, Time10Pos.x, Time10Pos.y);
	}
}
