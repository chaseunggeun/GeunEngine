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


		mPlayer = object::Instantiate<Player>(enums::eLayerType::Particle);
		// SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		// sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		/*graphics::Texture* pacmanTexture = Resources::Find<graphics::Texture>(L"MapleEffect");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", pacmanTexture
			, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.1f);
		animator->PlayAnimation(L"CatFrontMove", true);*/

		graphics::Texture* pacmanTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"DownWalk", pacmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"RightWalk", pacmanTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"UpWalk", pacmanTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"LeftWalk", pacmanTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"SitDown", pacmanTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"Grooming", pacmanTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->PlayAnimation(L"SitDown", false);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);

		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::Player);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		//bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Bubble");
		bgSr->SetTexture(bgTexture);

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