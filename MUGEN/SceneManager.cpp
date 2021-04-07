#include "SceneManager.h"
#include "Mugen.h"
#include "Image.h"
#include "Title.h"
#include "INGAME.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

HRESULT SceneManager::Init()
{
	for (int i = 0; i < (int)SCENE_STATE::NONE; i++)
	{
		switch (i)
		{
		case (int)SCENE_STATE::TITLE:
			scenes[i] = new Title();
			break;
		case (int)SCENE_STATE::INGAME:
			scenes[i] = new InGame();
			break;
		}
	}
	loadingScene = new Image();
	currentScene = SCENE_STATE::TITLE;
	LoadScene(SCENE_STATE::TITLE);
    return S_OK;
}

void SceneManager::Release()
{
	for (int i = 0; i < (int)SCENE_STATE::NONE; i++)
	{
		delete scenes[i];
	}
}

void SceneManager::Update()
{
	scenes[(int)currentScene]->Update();
}

void SceneManager::Render(HDC hdc)
{
	scenes[(int)currentScene]->Render(hdc);
}

void SceneManager::LoadScene(SCENE_STATE loadScene)
{
	if (loadScene == SCENE_STATE::TITLE)
	{
		GameData::GetLpInstance()->GameReset();
	}
	currentScene = loadScene;
	scenes[(int)currentScene]->Init();
}