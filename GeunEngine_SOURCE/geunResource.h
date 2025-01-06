#pragma once
#include "geunEntity.h"

namespace geun
{
	class Resource abstract : public Entity // �߻� Ŭ���� �޸� �Ҵ� X, ��ӹ޾Ƽ��� ����ؾ� ��
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // ���� �޸𸮿� �Ҵ��� �� �� ���� �� // ���� ���� �Լ�

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};

	//class Texture : public Resource;
	//class AudioClip : public Resource;
}
// ���ӿ��� ���Ǵ� �����͵��� ����

// �̹���, ����, 

// ���� ���� �÷��̵�����