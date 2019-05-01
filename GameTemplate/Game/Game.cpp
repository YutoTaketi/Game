#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"
#include "GameCameraPl.h"
#include "Stage.h"
#include "DemoCircle.h"
#include "DemoBall.h"
#include "Bee.h"
#include "CircleCharge.h"
#include "PlayerHpBer.h"
#include "GameClear.h"
#include "GameOver.h"


Game::Game()
{
}


Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCameraPl);
	DeleteGO(m_circleCharge);
	DeleteGO(m_HpBer);
	DeleteGOs("Bee");
	
	DeleteGOs("DemoCircle");
	//DeleteGO(m_level);
	
}
bool Game::Start()
{
	//プレイヤーのインスタンスを生成
	m_player = NewGO<Player>(0, "Player");
	//ゲームカメラのインスタンスを生成
	m_gameCameraPl = NewGO<GameCameraPl>(0, "GameCameraPl");
	
	//サークルチャージのインスタンスを生成
	m_circleCharge = NewGO<CircleCharge>(0, "CircleCharge");
	//プレイヤーのHPバーを表示
	m_HpBer = NewGO<PlayerHpBer>(0, "HpBer");

	////蜂のインスタンスを生成
	//m_bee = NewGO<Bee>(0, "Bee");
	//レベルを構築
	m_level.Init(L"level/DemoStage2.tkl", [&](LevelObjectData& objData) {
		
		
		if (objData.EqualObjectName(L"Bee") == true) {
           //蜂のオブジェクト
			Bee* bee = NewGO<Bee>(0,"Bee");
			bee->m_position = objData.position;
			bee->m_rotation = objData.rotation;
			bee->m_scale = objData.scale;
			return true;
		}


		
		return false;
		
	});
	return true;
}

void Game::Update()
{
	//m_bee = FindGO<Bee>("Bee");
	//Game* game = FindGO<Game>("Game");
	/*if (dethCount == 2)
	{
		NewGO<GameClear>(0, "GameClear");
		DeleteGO(this);
	}
	PlayerHpBer* HpBer = FindGO<PlayerHpBer>("HpBer");
	if (HpBer->w <= 0)
	{
		NewGO<GameOver>(0, "GameOver");
		DeleteGO(this);
	}*/
}