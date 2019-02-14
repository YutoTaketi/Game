#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"
#include "GameCameraPl.h"
#include "Stage.h"
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
	m_stage = NewGO<Stage>(0, "Stage");
	return true;
}

void Game::Update()
{
}