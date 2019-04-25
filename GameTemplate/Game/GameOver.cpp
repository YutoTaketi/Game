#include "stdafx.h"
#include "GameOver.h"
#include "Tittle.h"


GameOver::GameOver()
{
}


GameOver::~GameOver()
{
	DeleteGO(m_spriteRender);
}

bool GameOver::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/GameOver.dds", 1800.0f, 1000.0f);
	return true;
}

void GameOver::Update()
{
	if (Pad(0).IsTrigger(enButtonA)) {
		NewGO<Tittle>(0, "Tittle");
		DeleteGO(this);
	}
}
