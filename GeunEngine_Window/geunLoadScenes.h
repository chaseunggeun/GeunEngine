#pragma once
#include "..\\GeunEngine_SOURCE\\geunSceneManager.h"
#include "geunPlayScene.h"

namespace geun
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}

}