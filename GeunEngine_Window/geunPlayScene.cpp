#include "geunPlayScene.h"
#include "geunGameObject.h"
#include "geunPlayer.h"
#include "geunTransform.h"
#include "geunSpriteRenderer.h"
#include "geunInput.h"
#include "geunTitleScene.h"
#include "geunSceneManager.h"
#include "geunObject.h"
#include "geunTexture.h"
#include"geunResources.h"

namespace geun
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{

			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround);
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
			sr->SetTexture(bg);

			// 게임 오브젝트 생성 후에 레이어와 게임 오브젝트들의 init함수를 호출
			Scene::Initialize();
		}

		/*{
			GameObject* puddy = object::Instantiate<GameObject>
				(enums::eLayerType::Player, Vector2(150.0f, 150.0f));
			SpriteRenderer* sr = puddy->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"..\\Resources\\puddy.png");
		}*/
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}