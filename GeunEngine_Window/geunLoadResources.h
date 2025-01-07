#pragma once
#include "..\\GeunEngine_SOURCE\\geunResources.h"
#include "..\\GeunEngine_SOURCE\\geunTexture.h"

namespace geun
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PacMan", L"..\\Resources\\img\\pacman\\0.png");
	}

}