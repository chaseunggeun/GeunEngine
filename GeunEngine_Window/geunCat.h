#pragma once
#include "..\\GeunEngine_SOURCE\\geunGameObject.h"


namespace geun
{
	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}

