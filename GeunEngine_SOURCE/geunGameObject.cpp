#include "geunGameObject.h"
#include "geunInput.h"

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

		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		//�Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		//�Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� �� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		//�ٽ� ��� �귯���� ����
		(HBRUSH)SelectObject(hdc, oldBrush);
		//�Ķ� �귯�� ����
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
