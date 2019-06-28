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
#include "Tombo.h"   //敵



Game2::Game2()
{
}


Game2::~Game2()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCameraPl);
	DeleteGO(m_HpBer);
	DeleteGOs("Capsule");
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

	//トンボのインスタンスを生成
	m_tombo = NewGO<Tombo>(0, "Tombo");
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

		return false;

	});

	return true;
}

void Game2::Update()
{

}
