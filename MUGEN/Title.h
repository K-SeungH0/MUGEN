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
		Image* lpSelectIonImage;
		POINT pos;
		GameData::CHARACTER_NAME selectedCharacterName;
		Image* lpSelectedCharacterImage;
	};

	TITLE_MODE titleMode;

	Image* lpTitleImage;
	Image* lpSelectImage;
	Image* lpBuffer;
	Image* lpCompleteTimerImage;
	SelectCharacter selectableCharacters[(int)GameData::CHARACTER_NAME::NONE];
	SelectPlayer selectPlayers[(int)PLAYER_TYPE::NONE];

	int selectIndex;

	int elapsedTime;
	int speed;
	int completeTimer;
public:
	HRESULT Init() final;
	void Release() final;
	void Update() final;
	void Render(HDC hdc) final;
};

