#include "stdafx.h"
#include "LoadGamen.h"
#include "Game.h"
#include "StageNumber.h"  //制作中のみ
#include "Game2.h" //制作中のみ

LoadGamen::LoadGamen()
{
}


LoadGamen::~LoadGamen()
{
	DeleteGO(m_spriteRender);
}

bool LoadGamen::Start()
{
	//制作中のみ
	stagenumber = &StageNumber::GetInstance();
	stagenumber->SetStage(StageNumber::enState_Stage2);
	//ステージ1のロード画面を表示
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Load1.dds", 1300.0, 700.0);
	return true;
}

void LoadGamen::Update()
{
	LoadTimer++;
	if (LoadTimer == 70) {
		//NewGO<Game>(0, "Game");
		NewGO<Game2>(0, "Game2"); //制作中のみ
		DeleteGO(this);
	}
	
}
