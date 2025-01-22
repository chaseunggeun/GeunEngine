#pragma once
#include "..\\GeunEngine_SOURCE\\geunResources.h"
#include "..\\GeunEngine_SOURCE\\geunTexture.h"

namespace geun
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}

}