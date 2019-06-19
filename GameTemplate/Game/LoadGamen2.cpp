#include "stdafx.h"
#include "LoadGamen2.h"
#include "Game2.h"


LoadGamen2::LoadGamen2()
{
}


LoadGamen2::~LoadGamen2()
{
	DeleteGO(m_spriteRender);
}

bool LoadGamen2::Start()
{
	//�X�e�[�W2�̃��[�h��ʂ�\��
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Load2.dds", 1300.0, 700.0);
	return true;
}

void LoadGamen2::Update()
{
	LoadTimer++;
	if (LoadTimer == 70) {
		NewGO<Game2>(0, "Game2");
		DeleteGO(this);
	}
}