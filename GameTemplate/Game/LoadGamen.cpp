#include "stdafx.h"
#include "LoadGamen.h"
#include "Game.h"


LoadGamen::LoadGamen()
{
}


LoadGamen::~LoadGamen()
{
	DeleteGO(m_spriteRender);
}

bool LoadGamen::Start()
{
	//�X�e�[�W1�̃��[�h��ʂ�\��
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Load1.dds", 1300.0, 700.0);
	return true;
}

void LoadGamen::Update()
{
	LoadTimer++;
	if (LoadTimer == 70) {
		NewGO<Game>(0, "Game");
		DeleteGO(this);
	}
	
}
