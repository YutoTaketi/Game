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

Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{
	//プレイヤーのインスタンスを生成
	m_player = NewGO<Player>(0, "Player");
	//ゲームカメラのインスタンスを生成
	m_gameCameraPl = NewGO<GameCameraPl>(0, "GameCameraPl");
	//ステージ
	//m_stage = NewGO<Stage>(0, "Stage");
	//デモサークル
	//m_demoCircle = NewGO<DemoCircle>(0, "DemoCircle");

	//デモボール
	//m_demoBall = NewGO<DemoBall>(0, "DemoBall");

	//サークルチャージのインスタンスを生成
	m_circleCharge = NewGO<CircleCharge>(0, "CircleCharge");
	
	//蜂のインスタンスを生成
	m_bee = NewGO<Bee>(0, "Bee");
	//レベルを構築
	m_level.Init(L"level/DemoStage2.tkl", [&](LevelObjectData& objData) {
		
		
		if (objData.EqualObjectName(L"Bee") == true) {
           //蜂のオブジェクト
			Bee* m_bee = NewGO<Bee>(0);
			m_bee->m_position = objData.position;
			m_bee->m_rotation = objData.rotation;
			m_bee->m_scale = objData.scale;
			return true;
		}


		
		return false;
		
	});
	return true;
}

void Game::Update()
{
}