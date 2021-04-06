#include "Ingame.h"
#include "Image.h"
#include "Character.h"
#include "DIO.h"
#include "Chang.h"
#include "King.h"
#include "Controller.h"
#include "Title.h"
#include "GameData.h"

InGame::InGame()
{
}

InGame::~InGame()
{
}

void InGame::Init()
{
	Player1_HPUI = ImageManager::GetLpInstance()->GetImage("Player1_HPUI");
	Player2_HPUI = ImageManager::GetLpInstance()->GetImage("Player2_HPUI");
	Player1_HP = ImageManager::GetLpInstance()->GetImage("HP");
	Player2_HP = ImageManager::GetLpInstance()->GetImage("HP");
	Player1_DelayHP = ImageManager::GetLpInstance()->GetImage("Delay_HP");
	Player2_DelayHP = ImageManager::GetLpInstance()->GetImage("Delay_HP");
	lpKOImg = ImageManager::GetLpInstance()->GetImage("KO");
	UI_Time = ImageManager::GetLpInstance()->GetImage("UI_Time");

	lpPlayer1 = nullptr;
	lpPlayer2 = nullptr;

	lpCharacter1 = nullptr;
	lpCharacter2 = nullptr;

	switch(Player1)
	{
	case Chang:
		UI_Player1 = ImageManager::GetLpInstance()->GetImage("UI_Player1_Chang");
			break;
	case DIO:
		UI_Player1 = ImageManager::GetLpInstance()->GetImage("UI_Player1_Chang");
		break;
	case KING:
		UI_Player1 = ImageManager::GetLpInstance()->GetImage("UI_Player1_Chang");
		break;
	}
	switch (Player2)
		{
		case Chang:
			UI_Player1 = ImageManager::GetLpInstance()->GetImage("UI_Player1_Chang");
				break;
		case DIO:
			UI_Player1 = ImageManager::GetLpInstance()->GetImage("UI_Player1_Chang");
			break;
		case KING:
			UI_Player1 = ImageManager::GetLpInstance()->GetImage("UI_Player1_Chang");
			break;
		}
	Character* lpDIO = new DIO();
	lpDIO->Init();

	Character* lpKING = new King();
	lpKING->Init();

	Character* lpChang = new Chang();
	lpChang->Init();

	lpBuffer = new Image();
	lpBuffer->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);

	lpBgImg = new Image();
	if (FAILED(lpBgImg->Init("Image/UI/Battle/bgImage.bmp", WINSIZE_WIDTH, WINSIZE_HEIGHT)))
	{
		MessageBox(g_hWnd, "배경 로드 실패", "Error", MB_OK);
	}
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

	lpBgImg->Release();
	delete lpBgImg;

	lpBuffer->Release();
	delete lpBuffer;
}

void InGame::Update()
{
	if (KeyManager::GetLpInstance()->IsOnceKeyDown('P'))
	{
		isDebugMode = !isDebugMode;
	}

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
	lpPlayer1->GetPlayerType();

	
	ColliderManager::GetLpInstance()->Update();

	lpPlayer1->Update();
	lpPlayer2->Update();


	RECT player1Rect = lpPlayer1->GetLpCharacter()->GetHitRect();
	RECT player2Rect = lpPlayer2->GetLpCharacter()->GetHitRect();
	if (CollisionRect(player1Rect, player2Rect))
	{
//
		float diffX = (player1Rect.right - player1Rect.left) + (player2Rect.right - player2Rect.left) - (max(player1Rect.right, player2Rect.right) - min(player1Rect.left, player2Rect.left));
		lpPlayer1->GetLpCharacter()->Translate({ -diffX / 2, 0 });
		lpPlayer2->GetLpCharacter()->Translate({ -diffX / 2, 0 });
	}

	IsCollision(lpPlayer1->GetLpCharacter(), lpPlayer2->GetLpCharacter());
	IsCollision(lpPlayer2->GetLpCharacter(), lpPlayer1->GetLpCharacter());
}

void InGame::Render(HDC hdc)
{
	HDC hBackDC = lpBuffer->GetMemDC();

	lpBgImg->Render(hBackDC);
	lpPlayer1->Render(hBackDC);
	lpPlayer2->Render(hBackDC);
	if (Player1_HPUI)Player1_HPUI->Render(hBackDC, 0, 0);
	if (Player2_HPUI)Player2_HPUI->Render(hBackDC, WINSIZE_WIDTH - 385 * 1200 / WINSIZE_WIDTH, 0);
	if (Player1_DelayHP)Player1_DelayHP->Render(hBackDC, 93, 43);
	if (Player2_DelayHP)Player2_DelayHP->Render(hBackDC, WINSIZE_WIDTH - 358 * 1200 / WINSIZE_WIDTH, 43);
	if (Player1_HP)Player1_HP->Render(hBackDC, 93, 43);
	if (Player2_HP)Player2_HP->Render(hBackDC, WINSIZE_WIDTH - 358 * 1200 / WINSIZE_WIDTH, 43);
	if (lpKOImg)lpKOImg->Render(hBackDC, WINSIZE_WIDTH / 2 - 500 * 1200 / WINSIZE_WIDTH, WINSIZE_HEIGHT / 2 - 300 * 600 / WINSIZE_WIDTH, frame);
	if (UI_Time)UI_Time->Render(hBackDC, WINSIZE_WIDTH / 2 - 100 * 1200 / WINSIZE_WIDTH, 50 * 600 / WINSIZE_HEIGHT, time / 10);
	if (UI_Time)UI_Time->Render(hBackDC, WINSIZE_WIDTH / 2, 50 * 600 / WINSIZE_HEIGHT, time % 10);
	// 충돌체 렌더
	ColliderManager::GetLpInstance()->Render(hBackDC);
	
	// 이펙트 렌더
	EffectManager::GetLpInstance()->Render(hBackDC);

	MoveToEx(hBackDC, 0, WINSIZE_HEIGHT - 100, nullptr);
	LineTo(hBackDC, WINSIZE_WIDTH, WINSIZE_HEIGHT - 100);

	lpBuffer->Render(hdc);
}

bool InGame::IsCollision(Character* attacker, Character* defender)
{
	bool isCollision = false;
	RECT playerRect = {}, targetRect = {};
	POINTFLOAT point, playerPoint;
	float incl = 1;

	playerRect = defender->GetHitRect();
	playerPoint = { defender->GetPos().x, defender->GetPos().y - (playerRect.bottom - playerRect.top) / 2 };
	auto& lstColliders = ColliderManager::GetLpInstance()->GetLstColliders(attacker->GetPlayerType());
	for (auto it = lstColliders.begin(); it != lstColliders.end();)
	{
		targetRect = { (int)(it->pos.x - it->width / 2), (int)(it->pos.y - it->height / 2), (int)(it->pos.x + it->width / 2), (int)(it->pos.y + it->height / 2) };
		if (CollisionRect(playerRect, targetRect))
		{
			isCollision = true;

			incl = (it->pos.y - playerPoint.y) / (it->pos.x - playerPoint.x);
			point = { roundf(it->pos.x), incl * roundf(it->pos.x) + (it->pos.y - incl * it->pos.x) };
			if (playerPoint.x - it->pos.x < 0)
			{
				for (int i = 0; point.x + i >= playerPoint.x + 0.0001f; --i)
				{
					if (CollisionRectInPoint(playerRect, { (int)round(point.x + i + 0.0001f), (int)round(point.y + incl * i + 0.0001f) }))
					{
						point = { (float)round(point.x + i + 0.0001f), (float)round(point.y + incl * i + 0.0001f) };
						break;
					}
				}
			}
			else
			{
				for (int i = 0; point.x + i < playerPoint.x + 0.0001f; ++i)
				{
					if (CollisionRectInPoint(playerRect, { (int)round(point.x + i + 0.0001f), (int)round(point.y + incl * i + 0.0001f) }))
					{
						point = { (float)round(point.x + i + 0.0001f), (float)round(point.y + incl * i + 0.0001f) };
						break;
					}
				}
			}
			/* it->hitEffectKey */
			defender->Hit(it->damage, point, "KING_RIGHT_RANGE_ATTACK_EFFECT");

			if (isDebugMode && it->type == ColliderManager::COLLIDER_TYPE::STATIC)
			{
				++it;
			}
			else
			{
				it = lstColliders.erase(it);
			}
		}
		else ++it;
	}

	return isCollision;
}