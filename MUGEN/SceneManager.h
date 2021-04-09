#pragma once
#include "Singleton.h"
#include <Windows.h>

class GameScene;
class Image;
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
	GameScene* scenes[(int)SCENE_STATE::NONE];
	SCENE_STATE currentScene;

	Image* lpBuffer;
	Image* lpLoadingImage;
	HDC lastHdc;
	bool isLoading;
	// 투명도 (투명 0 ~ 불투명 255)
	int alpha;
public:
	SceneManager();
	~SceneManager();

	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);
	void LoadScene(SCENE_STATE loadScene, HDC lastHdc);
};