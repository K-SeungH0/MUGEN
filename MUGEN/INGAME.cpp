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
	state = INGAME_STATE::INTRO;

	lpBuffer = ImageManager::GetLpInstance()->GetImage("INGAME_BUFFER");
	lpPlayer1HpUi = ImageManager::GetLpInstance()->GetImage("Player1_HPUI");
	lpPlayer2HpUi = ImageManager::GetLpInstance()->GetImage("Player2_HPUI");
	lpPlayerHp = ImageManager::GetLpInstance()->GetImage("HP");
	lpPlayerDelayHp = ImageManager::GetLpInstance()->GetImage("Delay_HP");
	lpKoImg = ImageManager::GetLpInstance()->GetImage("KO");
	lpTime = ImageManager::GetLpInstance()->GetImage("UI_Time");

	lpControllerP1 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P1).lpController;
	lpControllerP2 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P2).lpController;

	lpCharacterP1 = lpControllerP1->GetLpCharacter();
	lpCharacterP2 = lpControllerP2->GetLpCharacter();

	lpPlayer1Ui = ImageManager::GetLpInstance()->GetImage("UI_Player1_" + lpCharacterP1->GetPlayerName());
	lpPlayer2Ui = ImageManager::GetLpInstance()->GetImage("UI_Player2_" + lpCharacterP2->GetPlayerName());

	time = 60;
	count = 0;
	elapsedTime = 0;
	frame = 0;

	prePlayerHp1 = (float)lpCharacterP1->GetHp();
	prePlayerHp2 = (float)lpCharacterP2->GetHp();

	return S_OK;
}

void InGame::Release()
{
}

void InGame::Update()
{
	if (KeyManager::GetLpInstance()->IsOnceKeyDown('P'))
	{
		isDebugMode = !isDebugMode;
	}

	if (state == INGAME_STATE::INTRO)
	{
		state = INGAME_STATE::REALTIME;
	}
	else if (state == INGAME_STATE::REALTIME)
	{
		if (++elapsedTime % 2 == 0)
		{
			++frame %= 33;
		}

		if (lpCharacterP1->GetHp() < prePlayerHp1)
		{
			prePlayerHp1 -= (prePlayerHp1 - lpCharacterP1->GetHp()) * 0.03f;
			if (prePlayerHp1 < lpCharacterP1->GetHp()) prePlayerHp1 = lpCharacterP1->GetHp();
		}
		if (lpCharacterP2->GetHp() < prePlayerHp2)
		{
			prePlayerHp2 -= (prePlayerHp2 - lpCharacterP2->GetHp()) * 0.03f;
			if (prePlayerHp2 < lpCharacterP2->GetHp()) prePlayerHp2 = lpCharacterP2->GetHp();
		}

		ColliderManager::GetLpInstance()->Update();

		lpControllerP1->Update();
		lpControllerP2->Update();

		RECT player1Rect = lpControllerP1->GetLpCharacter()->GetHitRect();
		RECT player2Rect = lpControllerP2->GetLpCharacter()->GetHitRect();
		if (CollisionRect(player1Rect, player2Rect))
		{
			float diffX = (player1Rect.right - player1Rect.left) + (player2Rect.right - player2Rect.left) - (max(player1Rect.right, player2Rect.right) - min(player1Rect.left, player2Rect.left));
			lpControllerP1->GetLpCharacter()->Translate({ -diffX / 2, 0 });
			lpControllerP2->GetLpCharacter()->Translate({ -diffX / 2, 0 });
		}

		IsCollision(lpControllerP1->GetLpCharacter(), lpControllerP2->GetLpCharacter());
		IsCollision(lpControllerP2->GetLpCharacter(), lpControllerP1->GetLpCharacter());

		if(time != 0)
		{
			if (elapsedTime % 70 == 0)
			{
				time--;
				if (!lpCharacterP1->IsAlive() || !lpCharacterP2->IsAlive())
				{
					count++;
					if (count == 10)
					{
						SceneManager::GetLpInstance()->LoadScene(SceneManager::SCENE_STATE::TITLE, lpBuffer->GetImageInfo()->hMemDC);
					}
				}
			}

		}
		else
		{
			SceneManager::GetLpInstance()->LoadScene(SceneManager::SCENE_STATE::TITLE, lpBuffer->GetImageInfo()->hMemDC);
		}
	}
}

void InGame::Render(HDC hdc)
{
	HDC hBackDC = lpBuffer->GetMemDC();
	ImageManager::GetLpInstance()->GetImage("BACK_IMAGE_02")->Render(hBackDC, 0, 0);
	ImageManager::GetLpInstance()->GetImage("BACK_IMAGE_01")->Render(hBackDC, 0, 0);
	ImageManager::GetLpInstance()->GetImage("BACK_IMAGE_03")->Render(hBackDC, 212, WINSIZE_HEIGHT - 134, (frame % 12) / 2);
	ImageManager::GetLpInstance()->GetImage("BACK_IMAGE_04")->Render(hBackDC, WINSIZE_WIDTH / 2 - 55, WINSIZE_HEIGHT / 2 + 105, (frame % 36) / 2);

	lpControllerP1->Render(hBackDC);
	lpControllerP2->Render(hBackDC);
	
	if (lpPlayer1HpUi)lpPlayer1HpUi->Render(hBackDC, 0, 0);
	if (lpPlayer2HpUi)lpPlayer2HpUi->Render(hBackDC, WINSIZE_WIDTH - 385 * 1200 / WINSIZE_WIDTH, 0);
	if (lpPlayerDelayHp)lpPlayerDelayHp->Render(hBackDC, { 93, 43}, float(prePlayerHp1 / MAX_HP),1);
	if (lpPlayerDelayHp)lpPlayerDelayHp->Render(hBackDC, { WINSIZE_WIDTH-109, 43 }, float(-prePlayerHp2 / MAX_HP),1);
	if (lpPlayerHp)lpPlayerHp->Render(hBackDC, {93 , 43 }, float(lpCharacterP1->GetHp()) / MAX_HP,1);
	if (lpPlayerHp)lpPlayerHp->Render(hBackDC, { WINSIZE_WIDTH - 109, 43}, float(-lpCharacterP2->GetHp()) / MAX_HP,1);
	
	if (lpTime)lpTime->Render(hBackDC, WINSIZE_WIDTH / 2 - 100 * 1200 / WINSIZE_WIDTH, 50 * 600 / WINSIZE_HEIGHT, time / 10);
	if (lpTime)lpTime->Render(hBackDC, WINSIZE_WIDTH / 2, 50 * 600 / WINSIZE_HEIGHT, time % 10);
	if (!lpCharacterP1->IsAlive() || !lpCharacterP2->IsAlive()) lpKoImg->Render(hBackDC, WINSIZE_WIDTH / 2 - 500 * 1200 / WINSIZE_WIDTH, WINSIZE_HEIGHT / 2 - 300 * 600 / WINSIZE_WIDTH, frame);;
	if (lpPlayer1Ui)lpPlayer1Ui->Render(hBackDC, 21, 25);
	if (lpPlayer2Ui)lpPlayer2Ui->Render(hBackDC, WINSIZE_WIDTH - 145, 25);
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