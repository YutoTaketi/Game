#include "stdafx.h"
#include "Game2.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "GameCameraPl.h"
#include "Player.h"
#include "CircleCharge.h"
//#include "PlayerHpBer.h"




Game2::Game2()
{
}


Game2::~Game2()
{

}

bool Game2::Start()
{
	//プレイヤーのインスタンスを生成
	//m_player = NewGO<Player>(0, "Player");
	//ゲームカメラのインスタンスを生成
	//m_gameCameraPl = NewGO<GameCameraPl>(0, "GameCameraPl");
	//平行光源のインスタンスを生成
	m_directionLig = NewGO<prefab::CDirectionLight>(0);
	m_directionLig->SetDirection({ 0.707f, -0.707f, 0.0f });
	m_directionLig->SetColor({ 10.0f, 10.0f, 10.0f, 1.0f });

	GraphicsEngine().GetShadowMap().SetLightDirection({ 0.707f, -0.707f, 0.0f });
	//レベルを構築
	m_level.Init(L"level/Stage2.tkl", [&](LevelObjectData& objData) {


		

		return false;

	});

	return true;
}

void Game2::Update()
{

}
