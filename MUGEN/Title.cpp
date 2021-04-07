#include "Title.h"
#include "Image.h"

HRESULT Title::Init()
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
		selectableCharacters[i].pos = { i * WINSIZE_WIDTH / 3 + selectableCharacters[i].lpCharacterImage->GetImageInfo()->width / 3, WINSIZE_HEIGHT / 2 };
		selectableCharacters[i].isSelected = false;
	}

	speed = 30;
	titleMode = TITLE_MODE::TITLE;
	selectIndex = 0;

	return S_OK;
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

	for (int i = 0; i < (int)GameData::CHARACTER_NAME::NONE; i++)
	{
		delete selectableCharacters[i].lpCharacterImage;
		selectableCharacters[i].lpCharacterImage = nullptr;
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
					if (selectPlayers[i].selectedCharacterName == GameData::CHARACTER_NAME::NONE)
					{
						++selectPlayers[i].lpSelectImage->GetImageInfo()->currentFrame %= selectPlayers[i].lpSelectImage->GetImageInfo()->maxFrame;
						break;
					}
				}
			}
			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_RIGHT))
			{
				selectIndex++;
				if (selectIndex >= (int)GameData::CHARACTER_NAME::NONE) selectIndex--;
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
					if (selectPlayers[i].selectedCharacterName == GameData::CHARACTER_NAME::NONE)
					{
						selectPlayers[i].selectedCharacterName = selectableCharacters[selectIndex].name;
						GameData::GetLpInstance()->SetCharacter((PLAYER_TYPE)i, selectPlayers[i].selectedCharacterName);
						selectIndex = 0;
						break;
					}
				}
			}
			break;
	}
	if (selectPlayers[(int)PLAYER_TYPE::P1].selectedCharacterName != GameData::CHARACTER_NAME::NONE &&
		selectPlayers[(int)PLAYER_TYPE::P2].selectedCharacterName != GameData::CHARACTER_NAME::NONE)
	{
		SceneManager::GetLpInstance()->LoadScene(SceneManager::SCENE_STATE::INGAME);
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
				if (selectPlayers[i].selectedCharacterName == GameData::CHARACTER_NAME::NONE)
				{
					selectPlayers[i].lpSelectImage->Render(hdc, selectableCharacters[selectIndex].pos.x + selectableCharacters[selectIndex].lpCharacterImage->GetImageInfo()->width / 3,
						selectableCharacters[selectIndex].pos.y + selectableCharacters[selectIndex].lpCharacterImage->GetImageInfo()->height, 
						selectPlayers[i].lpSelectImage->GetImageInfo()->currentFrame);
					break;
				}
			}
			for (int i = 0; i < (int)GameData::CHARACTER_NAME::NONE; i++)
			{
				selectableCharacters[i].lpCharacterImage->Render(hdc, selectableCharacters[i].pos.x, selectableCharacters[i].pos.y);
			}
			break;
	}
}

void Title::Load()
{

}
