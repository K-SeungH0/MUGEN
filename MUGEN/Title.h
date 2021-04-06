#pragma once
#include "GameUI.h"

class Image;
class Title : public GameUI
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
		CHARACTER_NAME name;
		bool isSelected;
	};

	struct SelectPlayer
	{
		Image* lpSelectImage;
		POINT pos;
		CHARACTER_NAME selectedCharacterName;
	};

	TITLE_MODE titleMode;

	Image* lpTitleImage;
	Image* lpBgImage;
	SelectCharacter selectCharacters[(int)CHARACTER_NAME::NONE];
	SelectPlayer selectPlayers[(int)PLAYER_TYPE::NONE];

	int selectIndex;

	int elapsedTime;
	int speed;
public:
	Title();
	~Title();
	void Init() final;
	void Release() final;
	void Update() final;
	void Render(HDC hdc) final;
};

