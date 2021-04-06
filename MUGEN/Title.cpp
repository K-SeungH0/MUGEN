#include "Title.h"
#include "Image.h"
#include "GameData.h"

Title::Title()
{
}

Title::~Title()
{
}

void Title::Init()
{
	elapsedTime = 0;
	
	lpTitleImage = ImageManager::GetLpInstance()->GetImage("TITLE");
	lpBgImage = ImageManager::GetLpInstance()->GetImage("BACK_TITLE");
	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		switch (i)
		{
			case (int)PLAYER_TYPE::P1:
				selectPlayers[i].lpSelectImage = ImageManager::GetLpInstance()->GetImage("SELECT_1P");
				break;
			case (int)PLAYER_TYPE::P2:
				selectPlayers[i].lpSelectImage = ImageManager::GetLpInstance()->GetImage("SELECT_2P");
				break;
		}
		selectPlayers[i].selectedCharacterName = CHARACTER_NAME::NONE;
	}
	
	for (int i = 0; i < (int)CHARACTER_NAME::NONE; i++)
	{
		switch (i)
		{
			case (int)CHARACTER_NAME::CHANG:
				selectCharacters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("CHANG_SELECTION");
				selectCharacters[i].name = CHARACTER_NAME::CHANG;
				break;
			case (int)CHARACTER_NAME::DIO:
				selectCharacters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("DIO_SELECTION");
				selectCharacters[i].name = CHARACTER_NAME::DIO;
				break;
			case (int)CHARACTER_NAME::KING:
				selectCharacters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("KING_SELECTION");
				selectCharacters[i].name = CHARACTER_NAME::KING;
				break;
		}
		selectCharacters[i].pos = { i * WINSIZE_WIDTH / 3 + selectCharacters[i].lpCharacterImage->GetImageInfo()->width / 3, WINSIZE_HEIGHT / 2 };
		selectCharacters[i].isSelected = false;
	}

	speed = 30;
	titleMode = TITLE_MODE::TITLE;
	selectIndex = 0;
}

void Title::Release()
{
	delete lpTitleImage;
	lpTitleImage = nullptr;

	for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
	{
		delete selectPlayers[i].lpSelectImage;
		selectPlayers[i].lpSelectImage = nullptr;
	}

	for (int i = 0; i < (int)CHARACTER_NAME::NONE; i++)
	{
		delete selectCharacters[i].lpCharacterImage;
		selectCharacters[i].lpCharacterImage = nullptr;
	}
}

void Title::Update()
{
	switch (titleMode)
	{
		case Title::TITLE_MODE::TITLE:
			if (++elapsedTime % speed == 0)
				++lpTitleImage->GetImageInfo()->currentFrame %= lpTitleImage->GetImageInfo()->maxFrame;

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
				for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
				{
					if (selectPlayers[i].selectedCharacterName == CHARACTER_NAME::NONE)
					{
						++selectPlayers[i].lpSelectImage->GetImageInfo()->currentFrame %= selectPlayers[i].lpSelectImage->GetImageInfo()->maxFrame;
						break;
					}
				}
			}
			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_RIGHT))
			{
				selectIndex++;
				if (selectIndex >= (int)CHARACTER_NAME::NONE) selectIndex--;
			}
			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_LEFT))
			{
				selectIndex--;
				if (selectIndex < 0) selectIndex++;
			}
			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_RETURN))
			{
				for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
				{
					if (selectPlayers[i].selectedCharacterName == CHARACTER_NAME::NONE)
					{
						selectPlayers[i].selectedCharacterName = selectCharacters[selectIndex].name;
						GameData::GetLpInstance()->GetCharacter((PLAYER_TYPE)i, selectPlayers[i].selectedCharacterName);
						selectIndex = 0;
						break;
					}
				}
			}
			break;
	}
}

void Title::Render(HDC hdc)
{
	lpBgImage->Render(hdc);
	switch (titleMode)
	{
		case Title::TITLE_MODE::TITLE:
		lpTitleImage->Render(hdc,0,0, lpTitleImage->GetImageInfo()->currentFrame);
			break;
		case Title::TITLE_MODE::SELECT:
			for (int i = 0; i < (int)PLAYER_TYPE::NONE; i++)
			{
				if (selectPlayers[i].selectedCharacterName == CHARACTER_NAME::NONE)
				{
					selectPlayers[i].lpSelectImage->Render(hdc, selectCharacters[selectIndex].pos.x + selectCharacters[selectIndex].lpCharacterImage->GetImageInfo()->width / 3,
						selectCharacters[selectIndex].pos.y + selectCharacters[selectIndex].lpCharacterImage->GetImageInfo()->height, 
						selectPlayers[i].lpSelectImage->GetImageInfo()->currentFrame);
					break;
				}
			}
			for (int i = 0; i < (int)CHARACTER_NAME::NONE; i++)
			{
				selectCharacters[i].lpCharacterImage->Render(hdc, selectCharacters[i].pos.x, selectCharacters[i].pos.y);
			}
			break;
	}
}
