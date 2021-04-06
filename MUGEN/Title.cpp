#include "Title.h"
#include "Image.h"

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
				players[i].lpSelectImage = ImageManager::GetLpInstance()->GetImage("SELECT_1P");
				break;
			case (int)PLAYER_TYPE::P2:
				players[i].lpSelectImage = ImageManager::GetLpInstance()->GetImage("SELECT_2P");
				break;
		}
		players[i].selectedCharacterName = CHARACTER_NAME::NONE;
	}
	
	for (int i = 0; i < (int)CHARACTER_NAME::NONE; i++)
	{
		switch (i)
		{
			case (int)CHARACTER_NAME::CHANG:
				characters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("CHANG_SELECTION");
				characters[i].name = CHARACTER_NAME::CHANG;
				break;
			case (int)CHARACTER_NAME::DIO:
				characters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("DIO_SELECTION");
				characters[i].name = CHARACTER_NAME::DIO;
				break;
			case (int)CHARACTER_NAME::KING:
				characters[i].lpCharacterImage = ImageManager::GetLpInstance()->GetImage("KING_SELECTION");
				characters[i].name = CHARACTER_NAME::KING;
				break;
		}
		characters[i].pos = { i * WINSIZE_WIDTH / 3 + characters[i].lpCharacterImage->GetImageInfo()->width / 3, WINSIZE_HEIGHT / 2 };
		characters[i].isSelected = false;
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
		delete players[i].lpSelectImage;
		players[i].lpSelectImage = nullptr;
	}

	for (int i = 0; i < (int)CHARACTER_NAME::NONE; i++)
	{
		delete characters[i].lpCharacterImage;
		characters[i].lpCharacterImage = nullptr;
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
					if (players[i].selectedCharacterName == CHARACTER_NAME::NONE)
					{
						++players[i].lpSelectImage->GetImageInfo()->currentFrame %= players[i].lpSelectImage->GetImageInfo()->maxFrame;
						break;
					}
				}
			}
			if (KeyManager::GetLpInstance()->IsOnceKeyDown(VK_RIGHT))
			{
				selectIndex++;
				if (selectIndex > (int)CHARACTER_NAME::NONE) selectIndex--;
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
					if (players[i].selectedCharacterName == CHARACTER_NAME::NONE)
					{
						players[i].selectedCharacterName = characters[selectIndex].name;
						
						// 테스트용
						switch (characters[selectIndex].name)
						{
							case CHARACTER_NAME::CHANG:
								MessageBox(g_hWnd, "CHANG을 선택했다!", "캐릭터 선택", MB_OK);
								break;
							case CHARACTER_NAME::DIO:								
								MessageBox(g_hWnd, "DIO을 선택했다!", "캐릭터 선택", MB_OK);
								break;
							case CHARACTER_NAME::KING:
								MessageBox(g_hWnd, "KING을 선택했다!", "캐릭터 선택", MB_OK);
								break;
						}
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
				if (players[i].selectedCharacterName == CHARACTER_NAME::NONE)
				{
					players[i].lpSelectImage->Render(hdc, characters[selectIndex].pos.x + characters[selectIndex].lpCharacterImage->GetImageInfo()->width / 3,
						characters[selectIndex].pos.y + characters[selectIndex].lpCharacterImage->GetImageInfo()->height, 
						players[i].lpSelectImage->GetImageInfo()->currentFrame);
					break;
				}
			}
			for (int i = 0; i < (int)CHARACTER_NAME::NONE; i++)
			{
				characters[i].lpCharacterImage->Render(hdc, characters[i].pos.x, characters[i].pos.y);
			}
			break;
	}
}
