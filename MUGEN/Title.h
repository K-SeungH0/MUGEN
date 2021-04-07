#pragma once
#include "GameScene.h"

class Image;

class Title : public GameScene
{
private:
	enum class TITLE_MODE 
	{
		TITLE,
		SELECT,
		NONE
	};

	struct SelectCharacter
	{
		Image* lpCharacterImage;
		POINT pos;
		GameData::CHARACTER_NAME name;
		bool isSelected;
	};

	struct SelectPlayer
	{
		Image* lpSelectImage;
		POINT pos;
		GameData::CHARACTER_NAME selectedCharacterName;
	};

	TITLE_MODE titleMode;

	Image* lpTitleImage;
	Image* lpBgImage;
	SelectCharacter selectableCharacters[(int)GameData::CHARACTER_NAME::NONE];
	SelectPlayer selectPlayers[(int)PLAYER_TYPE::NONE];

	int selectIndex;

	int elapsedTime;
	int speed;
public:
	HRESULT Init() final;
	void Release() final;
	void Update() final;
	void Render(HDC hdc) final;
};

