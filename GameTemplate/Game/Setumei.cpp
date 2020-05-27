#include "stdafx.h"
#include "Setumei.h"
#include "LoadGamen.h"

Setumei::Setumei()
{
}


Setumei::~Setumei()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteRender2);
}

bool Setumei::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/SetumeiHaikei.dds", 1400.0f, 1000.0f);
	m_spriteRender2 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender2->Init(L"sprite/Setumei.dds", 1000.0f, 780.0f);
	return true;
}

void Setumei::Update()
{
	SeniTimaer++;
	if (SeniTimaer == 180) {
		NewGO<LoadGamen>(0, "LoadGamen");
		DeleteGO(this);
	}
	m_spriteRender->SetPosition(m_position);
}