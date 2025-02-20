#pragma once
#include "geunComponent.h"

namespace geun
{
	class Script : public Component
	{
	public:

		Script();
		~Script();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}

