#include "stdafx.h"
#include "GameOver.h"
#include "Tittle.h"
#include "StageNumber.h"


GameOver::GameOver()
{
}


GameOver::~GameOver()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_gameObi);
	DeleteGO(m_overObi);
	DeleteGO(m_bgmSoundSource);
}

bool GameOver::Start()
{
	//ゲームオーバー画面
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/GameOver2.dds", 1400.0f, 750.0f);
	m_gameObi = NewGO<prefab::CSpriteRender>(0);
	m_gameObi->Init(L"sprite/GameObi.dds", 1350.0f, 750.0f);
	m_gameObiPos.x += 400.0f;
	m_overObi = NewGO<prefab::CSpriteRender>(0);
	m_overObi->Init(L"sprite/OverObi.dds", 1350.0f, 750.0f);
	m_overobiPos.x -= 400.0f;
	//ゲームオーバーサウンド
	overSS = NewGO<prefab::CSoundSource>(0);
	overSS->Init(L"sound/OverBGM.wav");
	overSS->SetVolume(0.5);
	overSS->Play(false);
	return true;
}

void GameOver::Update()
{
	//帯を動かす
	if (m_gameObiPos.x > 0.0f) {
		m_gameObiPos.x -= 5.0f;
	}
	if (m_overobiPos.x < 0.0f) {
		m_overobiPos.x += 5.0f;
	}
	//タイトル画面への移動
	if (m_gameObiPos.x <= 0.0f && m_overobiPos.x >= 0.0f) {
		stagenumber = &StageNumber::GetInstance();
		overTimer++;
		if (overTimer == 180) {
			NewGO<Tittle>(0, "Tittle");
			stagenumber->SetStage(StageNumber::enState_Stage1);
			DeleteGO(this);
			DeleteGO(overSS);
		}
	}
	
	m_gameObi->SetPosition(m_gameObiPos);
	m_overObi->SetPosition(m_overobiPos);
}
