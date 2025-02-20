#pragma once
#include "geunEntity.h"

namespace geun
{
	class Resource abstract : public Entity // 추상 클래스 메모리 할당 X, 상속받아서만 사용해야 함
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 실제 메모리에 할당을 할 수 없게 됨 // 순수 가상 함수

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};

	//class Texture : public Resource;
	//class AudioClip : public Resource;
}
// 게임에서 사용되는 데이터들의 종류

// 이미지, 사운드, 

// 저장 게임 플레이데이터