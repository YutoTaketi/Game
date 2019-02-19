#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"
#include "GameCameraPl.h"
#include "Stage.h"
#include "DemoCircle.h"
Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{
	//�v���C���[�̃C���X�^���X�𐶐�
	m_player = NewGO<Player>(0, "Player");
	//�Q�[���J�����̃C���X�^���X�𐶐�
	m_gameCameraPl = NewGO<GameCameraPl>(0, "GameCameraPl");
	//�X�e�[�W
	m_stage = NewGO<Stage>(0, "Stage");
	//�f���T�[�N��
	m_demoCircle = NewGO<DemoCircle>(0, "DemoCircle");

	return true;
}

void Game::Update()
{
}