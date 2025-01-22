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
#include "geunResources.h"
#include "geunPlayerScript.h"
#include "geunCamera.h"
#include "geunRenderer.h"
#include "geunAnimator.h"
#include "geunCat.h"
#include "geunCatScript.h"

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

		//main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(343.0, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();


		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* PlayerAnimator = mPlayer->AddComponent<Animator>();
		PlayerAnimator->CreateAnimation(L"Idle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		PlayerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);

		PlayerAnimator->CreateAnimation(L"DownWalk", playerTex
			, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);
		PlayerAnimator->CreateAnimation(L"RightWalk", playerTex
			, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		PlayerAnimator->CreateAnimation(L"UpWalk", playerTex
			, Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 8, 0.1f);
		PlayerAnimator->CreateAnimation(L"LeftWalk", playerTex
			, Vector2(1500.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);


		PlayerAnimator->PlayAnimation(L"Idle", false);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		//CAT
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		cat->AddComponent<CatScript>();

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->PlayAnimation(L"SitDown", false);
		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		// 게임 오브젝트 생성 후에 레이어와 게임 오브젝트들의 init함수를 호출
		Scene::Initialize();

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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
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