#include "Title.h"
#include "Image.h"

HRESULT Title::Init()
{
	elapsedTime = 0;
	
	if (!lpBuffer)
	{
		lpBuffer = new Image();
		lpBuffer->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);
	}

	lpTitleImage = ImageManager::GetLpInstance()->GetImage("TITLE");
	lpSelectImage = ImageManager::GetLpInstance()->GetImage("SELECT");
	lpCompleteTimerImage = ImageManager::GetLpInstance()->GetImage("UI_Time");
	lpLoadingImage = ImageManager::GetLpInstance()->GetImage("LOADING");

	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		switch (i)
		{
			case (int)PLAYER_TYPE::P1:
				selectPlayers[i].lpSelectIonImage = ImageManager::GetLpInstance()->GetImage("SELECT_1P");
				break;
			case (int)PLAYER_TYPE::P2:
				selectPlayers[i].lpSelectIonImage = ImageManager::GetLpInstance()->GetImage("SELECT_2P");
				break;
		}
		selectPlayers[i].selectedCharacterName = GameData::CHARACTER_NAME::NONE;
	}
	
	for (int i = 0; i < (int)GameData::CHARACTER_NAME::NONE; i++)
	{
		switch (i)
		{
			case (int)GameData::CHARACTER_NAME::CHANG:
				selectableCharacters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("CHANG_SELECTION");
				selectableCharacters[i].name = GameData::CHARACTER_NAME::CHANG;
				break;
			case (int)GameData::CHARACTER_NAME::DIO:
				selectableCharacters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("DIO_SELECTION");
				selectableCharacters[i].name = GameData::CHARACTER_NAME::DIO;
				break;
			case (int)GameData::CHARACTER_NAME::KING:
				selectableCharacters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("KING_SELECTION");
				selectableCharacters[i].name = GameData::CHARACTER_NAME::KING;
				break;
		}
		selectableCharacters[i].pos = { i * 240 + 160, 420 };
		selectableCharacters[i].isSelected = false;
	}

	speed = 30;
	titleMode = TITLE_MODE::TITLE;
	selectIndex = 0;
	completeTimer = - 1;
	imageAlpha = 250;
	return S_OK;
}

void Title::Release()
{
	delete lpTitleImage;
	lpTitleImage = nullptr;

	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		delete selectPlayers[i].lpSelectIonImage;
		selectPlayers[i].lpSelectIonImage = nullptr;
	}

	for (int i = 0; i < (int)GameData::CHARACTER_NAME::NONE; i++)
	{
		delete selectableCharacters[i].lpCharacterImage;
		selectableCharacters[i].lpCharacterImage = nullptr;
	}
}

void Title::Update()
{
	// 투명도 (투명 0 ~ 불투명 255)
	if (imageAlpha >= 1) imageAlpha -= 2;

	switch (titleMode)
	{
		case Title::TITLE_MODE::TITLE:
			if (++elapsedTime % speed == 0)
			{
				++lpTitleImage->GetImageInfo()->currentFrame %= lpTitleImage->GetImageInfo()->maxFrame;
			}

			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_SPACE) ||
				KeyManager::GetLpInstance()->IsOnceKeyDown(VK_RETURN))
			{
				titleMode = TITLE_MODE::SELECT;
				speed = 10;
			}
			break;
		case Title::TITLE_MODE::SELECT:
			if (++elapsedTime % speed == 0)
			{
				completeTimer--;
				for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
				{
					if (selectPlayers[i].selectedCharacterName == GameData::CHARACTER_NAME::NONE)
					{
						++selectPlayers[i].lpSelectIonImage->GetImageInfo()->currentFrame %= selectPlayers[i].lpSelectIonImage->GetImageInfo()->maxFrame;
						break;
					}
				}
			}
			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_RIGHT))
			{
				selectIndex++;
				if (selectIndex >= (int)GameData::CHARACTER_NAME::NONE) selectIndex = 0;
			}
			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_LEFT))
			{
				selectIndex--;
				if (selectIndex < 0) selectIndex = (int)GameData::CHARACTER_NAME::NONE - 1;
			}
			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_RETURN))
			{
				for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
				{
					if (selectPlayers[i].selectedCharacterName == GameData::CHARACTER_NAME::NONE)
					{
						selectPlayers[i].selectedCharacterName = selectableCharacters[selectIndex].name;
						selectPlayers[i].lpSelectedCharacterImage = selectableCharacters[(int)selectPlayers[i].selectedCharacterName].lpCharacterImage;

						GameData::GetLpInstance()->SetCharacter((PLAYER_TYPE)i, selectPlayers[i].selectedCharacterName);
						selectIndex = 0;
						break;
					}
				}
			}
			break;
	}
	if (selectPlayers[(int)PLAYER_TYPE::P1].selectedCharacterName != GameData::CHARACTER_NAME::NONE &&
		selectPlayers[(int)PLAYER_TYPE::P2].selectedCharacterName != GameData::CHARACTER_NAME::NONE &&
		speed != 100)
	{
		speed = 100;
		elapsedTime = 0;
		completeTimer = 2;
	}

	if (completeTimer == 0)
	{
		selectPlayers[(int)PLAYER_TYPE::P1].selectedCharacterName = GameData::CHARACTER_NAME::NONE;
		selectPlayers[(int)PLAYER_TYPE::P2].selectedCharacterName = GameData::CHARACTER_NAME::NONE;
		SceneManager::GetLpInstance()->LoadScene(SceneManager::SCENE_STATE::INGAME);
	}
}

void Title::Render(HDC hdc)
{
	HDC hBackDC = lpBuffer->GetMemDC();

	lpSelectImage->Render(hBackDC);

	switch (titleMode)
	{
		case Title::TITLE_MODE::TITLE:
		lpTitleImage->Render(hBackDC,0,0, lpTitleImage->GetImageInfo()->currentFrame);
			break;
		case Title::TITLE_MODE::SELECT:
			for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
			{
				if (selectPlayers[i].selectedCharacterName == GameData::CHARACTER_NAME::NONE)
				{
					selectPlayers[i].lpSelectIonImage->Render(hBackDC, 
						selectableCharacters[selectIndex].pos.x + selectableCharacters[selectIndex].lpCharacterImage->GetImageInfo()->width / 3,
						selectableCharacters[selectIndex].pos.y + selectableCharacters[selectIndex].lpCharacterImage->GetImageInfo()->height, 
						selectPlayers[i].lpSelectIonImage->GetImageInfo()->currentFrame);
					break;
				}
				else
				{
					selectPlayers[i].lpSelectedCharacterImage->Render(hBackDC, i * 810 + 115, 180, selectPlayers[i].lpSelectedCharacterImage->GetImageInfo()->currentFrame);
				}
			}
			for (int i = 0; i < (int)GameData::CHARACTER_NAME::NONE; i++)
			{
				selectableCharacters[i].lpCharacterImage->Render(hBackDC, selectableCharacters[i].pos.x, selectableCharacters[i].pos.y);
			}
			
			if (completeTimer > 0)
				lpCompleteTimerImage->Render(hBackDC, lpSelectImage->GetImageInfo()->width / 2 - 60, lpSelectImage->GetImageInfo()->height / 2 - 125, completeTimer);
			
			break;
	}
	lpLoadingImage->Render(imageAlpha, hBackDC);

	lpBuffer->Render(hdc);
}
