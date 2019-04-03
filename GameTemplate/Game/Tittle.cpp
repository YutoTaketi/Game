#include "stdafx.h"
#include "Tittle.h"
#include "Game.h"


Tittle::Tittle()
{
}


Tittle::~Tittle()
{
	DeleteGO(m_spriteRender);
}

bool Tittle::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/DemoStart.dds", 1800.0f, 1000.0f);
	return true;
}

void Tittle::Update()
{
	if (Pad(0).IsTrigger(enButtonA)) {
		NewGO<Game>(0, "Game");
		DeleteGO(this);
	}
}