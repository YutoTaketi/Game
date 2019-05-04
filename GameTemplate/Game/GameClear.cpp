#include "stdafx.h"
#include "GameClear.h"
#include "Tittle.h"


GameClear::GameClear()
{
}


GameClear::~GameClear()
{
	DeleteGO(m_spriteRender);
}

bool GameClear::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Game Clear.dds", 1800.0f, 1000.0f);
	return true;
}

void GameClear::Update()
{
	if (Pad(0).IsTrigger(enButtonA)) {
		NewGO<Tittle>(0, "Tittle");
		DeleteGO(this);
	}
}
