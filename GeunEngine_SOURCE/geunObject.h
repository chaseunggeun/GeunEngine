#pragma once
#include "geunComponent.h"
#include "geunGameObject.h"
#include "geunLayer.h"
#include "geunScene.h"
#include "geunSceneManager.h"
#include "geunTransform.h"

namespace geun::object
{
	template <typename T>
	static T* Instantiate(geun::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(geun::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);
		return gameObject;
	}
}