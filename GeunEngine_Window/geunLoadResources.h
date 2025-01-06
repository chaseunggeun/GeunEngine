#pragma once
#include "..\\GeunEngine_SOURCE\\geunResources.h"
#include "..\\GeunEngine_SOURCE\\geunTexture.h"

namespace geun
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
	}

}