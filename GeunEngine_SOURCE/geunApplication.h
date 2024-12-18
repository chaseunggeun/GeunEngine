#pragma once
#include "geunGameObject.h"

namespace geun
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
	};
}

