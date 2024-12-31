#pragma once
#include "geunEntity.h"
#include "geunComponent.h"

namespace geun
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* mImgae;
		UINT mWidth;
		UINT mHeight;
	};
}

