#include "Ingame.h"
#include "Image.h"
#include "DIO.h"
#include "Chang.h"
#include "Controller.h"

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
	UI_Time = ImageManager::GetLpInstance()->GetImage("UI_Time");


	Character* lpDIO = new DIO();
	lpDIO->Init();
	Character* lpChang = new DIO();
	lpChang->Init();

	lpPlayer1 = new Controller();
	lpPlayer1->Init();
	lpPlayer1->SetController(PLAYER_TYPE::P1, lpDIO);

	lpPlayer2 = new Controller();
	lpPlayer2->Init();
	lpPlayer2->SetController(PLAYER_TYPE::P2, lpChang);

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
	x = lpPlayer1->GetLpCharacter()->GetHp();
	lpPlayer1->GetPlayerType();
}

void InGame::Render(HDC hdc)
{
	POINTFLOAT Player1_HPUIPos = { 0, 0 };
	if (Player1_HPUI)Player1_HPUI->Render(hdc, Player1_HPUIPos.x, Player1_HPUIPos.y);
	POINTFLOAT Player2_HPUIPos = { WINSIZE_WIDTH - 465, 0 };
	if (Player2_HPUI)Player2_HPUI->Render(hdc, Player2_HPUIPos.x, Player2_HPUIPos.y);

	POINTFLOAT Player1_DelayHPPos = { 93,43 };
	if (Player1_DelayHP)Player1_DelayHP->Render(hdc, Player1_DelayHPPos.x, Player1_DelayHPPos.y);
	POINTFLOAT Player2_DelayHPPos = { WINSIZE_WIDTH - 438, 43 };
	if (Player2_DelayHP)Player2_DelayHP->Render(hdc, Player2_DelayHPPos.x, Player2_DelayHPPos.y);

	POINTFLOAT Player1_HPPos = { 93,43 };
	if (Player1_HP)Player1_HP->Render(hdc, Player1_HPPos.x, Player1_HPPos.y);
	POINTFLOAT Player2_HPPos = { WINSIZE_WIDTH - 438, 43 };
	if (Player2_HP)Player2_HP->Render(hdc, Player2_HPPos.x, Player2_HPPos.y);

	POINTFLOAT KOPos = { WINSIZE_WIDTH/2 - 580, WINSIZE_HEIGHT/2 - 300};
	if (lpKOImg)lpKOImg->Render(hdc, KOPos.x, KOPos.y, frame);

	for(int i = 0; i <= 10; i++)
		{
			if (i == time / 10)
			{
				POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 200, 50 };
				if (UI_Time)UI_Time->Render(hdc, Time10Pos.x, Time10Pos.y,i);
			}
			if (i == time % 10)
			{
				POINTFLOAT Time10Pos = { WINSIZE_WIDTH / 2 - 100, 50 };
				if (UI_Time)UI_Time->Render(hdc, Time10Pos.x, Time10Pos.y,i);
			}
		}
}
