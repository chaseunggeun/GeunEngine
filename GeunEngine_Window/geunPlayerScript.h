#pragma once
#include "..\\GeunEngine_SOURCE\\geunScript.h"

namespace geun
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}
