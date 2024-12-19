#include "geunGameObject.h"
#include "geunInput.h"
#include "geunTime.h"

namespace geun
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{
		  
	}
	void GameObject::Render(HDC hdc)
	{
		//파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		//파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		//다시 흰색 브러쉬로 선택
		(HBRUSH)SelectObject(hdc, oldBrush);
		//파랑 브러쉬 삭제
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
