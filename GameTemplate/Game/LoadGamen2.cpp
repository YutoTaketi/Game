#include "stdafx.h"
#include "LoadGamen2.h"
#include "Game2.h"
#include "StageNumber.h"


LoadGamen2::LoadGamen2()
{
}


LoadGamen2::~LoadGamen2()
{
	DeleteGO(m_spriteRender);
}

bool LoadGamen2::Start()
{
	//ステージ2のロード画面を表示
	stagenumber = &StageNumber::GetInstance();
	stagenumber->SetStage(StageNumber::enState_Stage2 );
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Load2.dds", 1300.0, 750.0);
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