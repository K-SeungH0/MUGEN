#pragma once
#include "Singleton.h"
#include <Windows.h>

class Image;
class GameScene;
enum class SCENE_STATE;

class SceneManager : public Singleton<SceneManager>
{
public:
	enum class SCENE_STATE
	{
		TITLE,
		INGAME,
		NONE
	};
private:
	Image* lpBuffer;
	Image* lpBgImg;

	GameScene* scenes[(int)SCENE_STATE::NONE];
	SCENE_STATE currentScene;

public:
	SceneManager();
	~SceneManager();
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void ChangeScene(SCENE_STATE chageScene);
};

