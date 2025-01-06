#pragma once
#include "..\\GeunEngine_SOURCE\\geunSceneManager.h"
#include "geunPlayScene.h"
#include "geunTitleScene.h"
#include "geunEndScene.h"

namespace geun
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		//SceneManager::LoadScene(L"TitleScene");
		SceneManager::LoadScene(L"PlayScene");
		//SceneManager::LoadScene(L"EndScene");
	}

}