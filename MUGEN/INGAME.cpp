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
	lpPlayer1HpUi = ImageManager::GetLpInstance()->GetImage("Player1_HPUI");
	lpPlayer2HpUi = ImageManager::GetLpInstance()->GetImage("Player2_HPUI");
	lpPlayer1Hp = ImageManager::GetLpInstance()->GetImage("HP");
	lpPlayer2Hp = ImageManager::GetLpInstance()->GetImage("HP");
	lpPlayer1DelayHp = ImageManager::GetLpInstance()->GetImage("Delay_HP");
	lpPlayer2DelayHp = ImageManager::GetLpInstance()->GetImage("Delay_HP");
	lpKoImg = ImageManager::GetLpInstance()->GetImage("KO");
	lpTime = ImageManager::GetLpInstance()->GetImage("UI_Time");

	lpBuffer = new Image();
	lpBuffer->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);

	lpControllerP1 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P1).lpController;
	lpControllerP2 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P2).lpController;

	lpCharacterP1 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P1).lpCharacter;
	lpCharacterP2 = GameData::GetLpInstance()->GetPlayer(PLAYER_TYPE::P2).lpCharacter;

	lpControllerP1->SetController(PLAYER_TYPE::P1, lpCharacterP1);
	lpControllerP2->SetController(PLAYER_TYPE::P2, lpCharacterP2);



if ("Chang" == lpCharacterP1->GetPlayerName())
{
	lpPlayer1Ui = ImageManager::GetLpInstance()->GetImage("UI_Player1_Chang");
}

if ("DIO" == lpCharacterP1->GetPlayerName())
{
	lpPlayer1Ui = ImageManager::GetLpInstance()->GetImage("UI_Player1_DIO");
}
if ("KING" == lpCharacterP1->GetPlayerName())
{
	lpPlayer1Ui = ImageManager::GetLpInstance()->GetImage("UI_Player1_KING");
}
if ("Chang" == lpCharacterP2->GetPlayerName())
{
	lpPlayer2Ui = ImageManager::GetLpInstance()->GetImage("UI_Player2_Chang");
}

if ("DIO" == lpCharacterP2->GetPlayerName())
{
	lpPlayer2Ui = ImageManager::GetLpInstance()->GetImage("UI_Player2_DIO");
}

if ("KING" == lpCharacterP2->GetPlayerName())
{
	lpPlayer2Ui = ImageManager::GetLpInstance()->GetImage("UI_Player2_KING");
}

	return S_OK;
}

void InGame::Release()
{
	lpPlayer1HpUi->Release();
	lpPlayer2HpUi->Release();
	lpPlayer1Hp->Release();
	lpPlayer2Hp->Release();
	lpPlayer1DelayHp->Release();
	lpPlayer2DelayHp->Release();
	lpKoImg->Release();

	lpBuffer->Release();
	delete lpBuffer;
}

void InGame::Update()
{
	lpCharacterP1;
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

	lpControllerP1->GetPlayerType();
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
			if (lpCharacterP1->GetHp() == 0 || lpCharacterP2->GetHp() == 0)
			{
				lpKo = ImageManager::GetLpInstance()->GetImage("KO");
				count++;
				if (count == 10)
					{
						lpKo = nullptr;
						count -= 10;
						time = 60;
						SceneManager::GetLpInstance()->LoadScene(SceneManager::SCENE_STATE::TITLE, lpBuffer->GetImageInfo()->hMemDC);
					}
			}
		}

	}
	else
	{
		time = 60;
		SceneManager::GetLpInstance()->LoadScene(SceneManager::SCENE_STATE::TITLE, lpBuffer->GetImageInfo()->hMemDC);
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
	if (lpPlayer1DelayHp)lpPlayer1DelayHp->Render(hBackDC, { 93, 43}, float(lpCharacterP1->GetHp() / MAX_HP),1);
	if (lpPlayer2DelayHp)lpPlayer2DelayHp->Render(hBackDC, { WINSIZE_WIDTH-109, 43 }, float(-lpCharacterP2->GetHp() / MAX_HP),1);
	if (lpPlayer1Hp)lpPlayer1Hp->Render(hBackDC, {93 , 43 }, float(lpCharacterP1->GetHp()) / MAX_HP,1);
	if (lpPlayer2Hp)lpPlayer2Hp->Render(hBackDC, { WINSIZE_WIDTH - 109, 43}, float(-lpCharacterP2->GetHp()) / MAX_HP,1);
	
	if (lpTime)lpTime->Render(hBackDC, WINSIZE_WIDTH / 2 - 100 * 1200 / WINSIZE_WIDTH, 50 * 600 / WINSIZE_HEIGHT, time / 10);
	if (lpTime)lpTime->Render(hBackDC, WINSIZE_WIDTH / 2, 50 * 600 / WINSIZE_HEIGHT, time % 10);
	if (lpKo)lpKo->Render(hBackDC, WINSIZE_WIDTH / 2 - 500 * 1200 / WINSIZE_WIDTH, WINSIZE_HEIGHT / 2 - 300 * 600 / WINSIZE_WIDTH, frame);;
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