#include "stdafx.h"
#include "GameClear.h"
#include "Tittle.h"
#include "LoadGamen2.h"
#include "StageNumber.h"


GameClear::GameClear()
{
}


GameClear::~GameClear()
{
	DeleteGO(m_bgmSoundSource);
	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteStage);
	DeleteGO(m_ClearObi);
}

bool GameClear::Start()
{
	stagenumber = &StageNumber::GetInstance();
	switch (stagenumber->GetStageNumber())
	{
		//ステージ１をクリアしたときのクリア画面
	case StageNumber::enState_Stage1:
		m_spriteRender = NewGO<prefab::CSpriteRender>(0);
		m_spriteRender->Init(L"sprite/Clear.dds", 1400.0f, 1000.0f);
		m_spriteStage = NewGO<prefab::CSpriteRender>(0);
		m_spriteStage->Init(L"sprite/Stage1obi.dds", 1300.0f, 750.0f);
		spriteStagePos.x -= 400.0f;
		spriteStagePos.y += 50.0f;
		m_ClearObi = NewGO<prefab::CSpriteRender>(0);
		m_ClearObi->Init(L"sprite/ClearObi.dds", 1300.0f, 750.0f);
		clearobiPos.x += 400.0f;
		clearobiPos.y -= 50.0f;
		clearSS = NewGO<prefab::CSoundSource>(0);
		clearSS->Init(L"sound/ClearBGM.wav");
		clearSS->Play(false);
		break;
		//ステージ２をクリアしたときのクリア画面
	case StageNumber::enState_Stage2:
		m_spriteRender = NewGO<prefab::CSpriteRender>(0);
		m_spriteRender->Init(L"sprite/Clear2.dds", 1400.0f, 750.0f);
		m_spriteStage = NewGO<prefab::CSpriteRender>(0);
		m_spriteStage->Init(L"sprite/Stage2obi.dds", 1300.0f, 750.0f);
		spriteStagePos.x -= 400.0f;
		m_ClearObi = NewGO<prefab::CSpriteRender>(0);
		m_ClearObi->Init(L"sprite/ClearObi2.dds", 1300.0f, 750.0f);
		clearobiPos.x += 400.0f;
		break;
	}
	
	return true;
}

void GameClear::Update()
{
	//帯を動かす
	if (spriteStagePos.x < 0) {
		spriteStagePos.x += 5.0f;
	}
	if (clearobiPos.x > 0) {
		clearobiPos.x -= 5.0f;
	}
	//ステージ２へ遷移
	if (stagenumber->GetStageNumber() == StageNumber::enState_Stage1)
	{
		if (spriteStagePos.x >= 0 && clearobiPos.x <= 0) {
			clearTimer++;
			if (clearTimer == 60) {
				NewGO<LoadGamen2>(0, "LoadGamen2");
				DeleteGO(this);
				DeleteGO(clearSS);
			}
		}
		
	}
	//タイトル画面へ遷移
	if (stagenumber->GetStageNumber() == StageNumber::enState_Stage2)
	{
		if (spriteStagePos.x >= 0 && clearobiPos.x <= 0) {
			stagenumber = &StageNumber::GetInstance();
			clearTimer++;
			if (clearTimer == 120) {
				NewGO<Tittle>(0, "Tittle");
				stagenumber->SetStage(StageNumber::enState_Stage1);
				DeleteGO(this);
			}
		}
		
	}
	

	m_spriteStage->SetPosition(spriteStagePos);
	m_ClearObi->SetPosition(clearobiPos);
}
