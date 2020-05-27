#include "stdafx.h"
#include "Game2.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "GameCameraPl.h"
#include "Player.h"
#include "CircleCharge.h"
#include "PlayerHpBer.h"
#include "Capsule.h"
#include "StageNumber.h"
#include "Kabuto.h"  //敵
#include "Kabuto2.h"
#include "Tombo.h"   //敵
#include "SpornBiru.h"
#include "GameClear.h"
#include "GameOver.h"



Game2::Game2()
{
}


Game2::~Game2()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCameraPl);
	DeleteGO(m_directionLig);
	DeleteGO(m_circleCharge);
	DeleteGO(m_HpBer);
	DeleteGO(game2SS);
	DeleteGOs("Capsule");
	DeleteGOs("Kabuto");
	DeleteGOs("Kabuto2");
	DeleteGOs("DemoCircle");
	DeleteGOs("SpornBiru");
	DeleteGOs("Tombo");
	DeleteGOs("TomboJr");
	DeleteGOs("Game2BGM");
}

bool Game2::Start()
{
	//プレイヤーのインスタンスを生成
	m_player = NewGO<Player>(0, "Player");
	//ゲームカメラのインスタンスを生成
	m_gameCameraPl = NewGO<GameCameraPl>(0, "GameCameraPl");
	//平行光源のインスタンスを生成
	m_directionLig = NewGO<prefab::CDirectionLight>(0);
	m_directionLig->SetDirection({ 0.707f, -0.707f, 0.0f });
	m_directionLig->SetColor({ 10.0f, 10.0f, 10.0f, 1.0f });

	m_circleCharge = NewGO<CircleCharge>(0, "CircleCharge");
	GraphicsEngine().GetShadowMap().SetLightDirection({ 0.707f, -0.707f, 0.0f });
	
	//プレイヤーのHPバーを表示
	m_HpBer = NewGO<PlayerHpBer>(0, "HpBer");

	
	//レベルを構築
	m_level.Init(L"level/Stage2.tkl", [&](LevelObjectData& objData) {

		 if (objData.EqualObjectName(L"Capsule2") == true) {
			//カプセルのインスタンスを生成
			Capsule* capsule = NewGO<Capsule>(0, "Capsule");
			capsule->m_position = objData.position;
			capsule->m_rotation = objData.rotation;
			capsule->m_scale = objData.scale;
			return true;
		 }
		
		 else if (objData.EqualObjectName(L"Kabuto") == true) {
			 //カブトのオブジェクト
			 Kabuto* kabuto = NewGO<Kabuto>(0, "Kabuto");
			 kabuto->m_position = objData.position;
			 kabuto->m_rotation = objData.rotation;
			 kabuto->m_scale = objData.scale;
			 return true;
		 }

		 else if (objData.EqualObjectName(L"Kabuto2") == true) {
			 //カブトのオブジェクト
			 Kabuto2* kabuto2 = NewGO<Kabuto2>(0, "Kabuto2");
			 kabuto2->m_position = objData.position;
			 kabuto2->m_rotation = objData.rotation;
			 kabuto2->m_scale = objData.scale;
			 return true;
		 }

		 else if (objData.EqualObjectName(L"SpornBiru") == true) {
			 //カプセルのインスタンスを生成
			 SpornBiru* spornBiru = NewGO<SpornBiru>(0, "SpornBiru");
			 spornBiru->m_position = objData.position;
			 spornBiru->m_rotation = objData.rotation;
			 spornBiru->m_scale = objData.scale;
			 return true;
		 }
		 //BGMを再生
		 game2SS = NewGO<prefab::CSoundSource>(0, "Game2BGM");
		 game2SS->Init(L"sound/Stage2BGM.wav");
		 game2SS->SetVolume(0.2f);
		 game2SS->Play(true);
		return false;

	});

	return true;
}

void Game2::Update()
{
	if (KabutoDethCount == 13) {
		if (BossFlag == 0) {
			//トンボのインスタンスを生成
			m_tombo = NewGO<Tombo>(0, "Tombo");
			BossFlag = 1;
			KabutoDethCount = 0;
		}    //ボススポーン
	}

	//クリア画面表示
	if (clearHantei == 1)
	{
		gameEndTimer++;
		if (gameEndTimer == 200) {
			NewGO<GameClear>(0, "GameClear");
			DeleteGO(this);
			DeleteGO(game2SS);
			BossFlag = 0;
		}

	}

	//ゲームオーバー
	PlayerHpBer* HpBer = FindGO<PlayerHpBer>("HpBer");
	if (HpBer->w <= 0 && clearHantei == 0)
	{
	   NewGO<GameOver>(0, "GameOver");
	   DeleteGO(this);
	   DeleteGO(game2SS);
	   BossFlag = 0;
	}
}
