#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"
#include "GameCameraPl.h"
#include "Stage.h"
#include "DemoCircle.h"
#include "DemoBall.h"
#include "Bee.h"
#include "Bee2.h"
#include "Boss.h"   //お試し
#include "Capsule.h"
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
	DeleteGOs("Bee2");
	DeleteGOs("Boss");
	DeleteGOs("Capsule");
	DeleteGOs("DemoCircle");
	DeleteGO(m_bgmSoundSource);
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
	
	//ボスのインスタンス//お試し
	//m_boss = NewGO<Boss>(0, "Boss");

	gameSS = NewGO<prefab::CSoundSource>(0);
	gameSS->Init(L"sound/GameSoundDemo.wav");
	gameSS->Play(true);
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

		else if (objData.EqualObjectName(L"Bee2") == true) {
			//蜂のオブジェクト
			Bee2* bee2 = NewGO<Bee2>(0, "Bee2");
			bee2->m_position = objData.position;
			bee2->m_rotation = objData.rotation;
			bee2->m_scale = objData.scale;
			return true;
		}
		
		else if (objData.EqualObjectName(L"Capsule") == true) {
			//カプセルのインスタンスを生成
			Capsule* capsule = NewGO<Capsule>(0, "Capsule");
			capsule->m_position = objData.position;
			capsule->m_rotation = objData.rotation;
			capsule->m_scale = objData.scale;
			return true;
		}

		
		return false;
		
	});
	return true;
}

void Game::Update()
{
	//Beeを一定数倒したらBoss(カマキリ)出現
	if (dethCount == 4) {
	  if (BossFlag == 0) {
		m_boss = NewGO<Boss>(0, "Boss");
		BossFlag = 1;
		}
	  //ボスバトルBGMに切り替わる
	}

	//m_bee = FindGO<Bee>("Bee");
	
	if ( clearHantei == 1)
	{ 
		gameEndTimer++;
		if (gameEndTimer == 200) {
			NewGO<GameClear>(0, "GameClear");
			DeleteGO(this);
			DeleteGO(gameSS);
		}
		
	}
	/*PlayerHpBer* HpBer = FindGO<PlayerHpBer>("HpBer");
	if (HpBer->w <= 0)
	{
		NewGO<GameOver>(0, "GameOver");
		DeleteGO(this);
		DeleteGO(gameSS);
	}*/
}