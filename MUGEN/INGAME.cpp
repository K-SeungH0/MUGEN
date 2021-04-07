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

	//Character* lpDIO = new DIO();
	//lpDIO->Init();

	//Character* lpKING = new King();
	//lpKING->Init();

	//Character* lpChang = new Chang();
	//lpChang->Init();

	lpBuffer = new Image();
	lpBuffer->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);

	lpController_P1 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P1).lp_Controller;
	lpController_P2 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P2).lp_Controller;

	lpCharacter_P1 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P1).lp_Character;
	lpCharacter_P2 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P2).lp_Character;

	lpController_P1->SetController(PLAYER_TYPE::P1, lpCharacter_P1);
	lpController_P2->SetController(PLAYER_TYPE::P2, lpCharacter_P2);

	//lpController_P1 = new Controller();
	//lpController_P1->Init();
	//switch ((int)lpCharacter_P1)
	//{
	//case 0:
	//	lpController_P1->SetController(PLAYER_TYPE::P1, lpChang);
	//	break;
	//case 1:
	//	lpController_P1->SetController(PLAYER_TYPE::P1, lpDIO);
	//	break;
	//case 2:
	//	lpController_P1->SetController(PLAYER_TYPE::P1, lpKING);
	//	break;
	//}

	//lpController_P2 = new Controller();
	//lpController_P2->Init();
	//switch ((int)lpCharacter_P2)
	//{
	//case 0:
	//	lpController_P2->SetController(PLAYER_TYPE::P2, lpChang);
	//	break;
	//case 1:
	//	lpController_P2->SetController(PLAYER_TYPE::P2, lpDIO);
	//	break;
	//case 2:
	//	lpController_P2->SetController(PLAYER_TYPE::P2, lpKING);
	//	break;
	//}

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

	lpBuffer->Release();
	delete lpBuffer;
}

void InGame::Update()
{
	lpCharacter_P1;
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
	lpController_P1->GetPlayerType();

	
	ColliderManager::GetLpInstance()->Update();

	lpController_P1->Update();
	lpController_P2->Update();


	RECT player1Rect = lpController_P1->GetLpCharacter()->GetHitRect();
	RECT player2Rect = lpController_P2->GetLpCharacter()->GetHitRect();
	if (CollisionRect(player1Rect, player2Rect))
	{
//
		float diffX = (player1Rect.right - player1Rect.left) + (player2Rect.right - player2Rect.left) - (max(player1Rect.right, player2Rect.right) - min(player1Rect.left, player2Rect.left));
		lpController_P1->GetLpCharacter()->Translate({ -diffX / 2, 0 });
		lpController_P2->GetLpCharacter()->Translate({ -diffX / 2, 0 });
	}

	IsCollision(lpController_P1->GetLpCharacter(), lpController_P2->GetLpCharacter());
	IsCollision(lpController_P2->GetLpCharacter(), lpController_P1->GetLpCharacter());
}

void InGame::Render(HDC hdc)
{
	HDC hBackDC = lpBuffer->GetMemDC();
	ImageManager::GetLpInstance()->GetImage("BACK_IMAGE_02")->Render(hBackDC, 0, 0);
	ImageManager::GetLpInstance()->GetImage("BACK_IMAGE_01")->Render(hBackDC, 0, 0);
	ImageManager::GetLpInstance()->GetImage("BACK_IMAGE_03")->Render(hBackDC, 212, WINSIZE_HEIGHT - 134, (frame % 12) / 2);
	ImageManager::GetLpInstance()->GetImage("BACK_IMAGE_04")->Render(hBackDC, WINSIZE_WIDTH / 2 - 55, WINSIZE_HEIGHT / 2 + 105, (frame % 36) / 2);

	lpController_P1->Render(hBackDC);
	lpController_P2->Render(hBackDC);
	if (Player1_HPUI)Player1_HPUI->Render(hBackDC, 0, 0);
	if (Player2_HPUI)Player2_HPUI->Render(hBackDC, WINSIZE_WIDTH - 385 * 1200 / WINSIZE_WIDTH, 0);
	if (Player1_DelayHP)Player1_DelayHP->Render(hBackDC, { 93, 43}, float(lpCharacter_P1->GetHp() / MAX_HP),1);
	if (Player2_DelayHP)Player2_DelayHP->Render(hBackDC, { WINSIZE_WIDTH-109, 43 }, float(-lpCharacter_P2->GetHp() / MAX_HP),1);
	if (Player1_HP)Player1_HP->Render(hBackDC, {93 , 43 }, float(lpCharacter_P1->GetHp()) / MAX_HP,1);
	if (Player2_HP)Player2_HP->Render(hBackDC, { WINSIZE_WIDTH - 109, 43}, float(-lpCharacter_P2->GetHp()) / MAX_HP,1);
	
	if (UI_Time)UI_Time->Render(hBackDC, WINSIZE_WIDTH / 2 - 100 * 1200 / WINSIZE_WIDTH, 50 * 600 / WINSIZE_HEIGHT, time / 10);
	if (UI_Time)UI_Time->Render(hBackDC, WINSIZE_WIDTH / 2, 50 * 600 / WINSIZE_HEIGHT, time % 10);
	if(lpCharacter_P1->GetHp()==0|| lpCharacter_P2->GetHp()==0)
	lpKOImg->Render(hBackDC, WINSIZE_WIDTH / 2 - 500 * 1200 / WINSIZE_WIDTH, WINSIZE_HEIGHT / 2 - 300 * 600 / WINSIZE_WIDTH, frame);
	// 충돌체 렌더
	ColliderManager::GetLpInstance()->Render(hBackDC);
	
	// 이펙트 렌더
	EffectManager::GetLpInstance()->Render(hBackDC);
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
			defender->Hit(it->damage, point, it->hitEffectKey);

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