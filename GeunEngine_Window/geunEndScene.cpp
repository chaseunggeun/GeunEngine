#include "geunEndScene.h"
#include "geunGameObject.h"
#include "geunPlayer.h"
#include "geunTransform.h"
#include "geunSpriteRenderer.h"

namespace geun
{
	EndScene::EndScene()
	{
	}
	EndScene::~EndScene()
	{
	}
	void EndScene::Initialize()
	{
		{
			Player* bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"..\\Resources\\puddy.png");


			AddGameObject(bg, eLayerType::BackGround);
		}
	}
	void EndScene::Update()
	{
		Scene::Update();
	}
	void EndScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}