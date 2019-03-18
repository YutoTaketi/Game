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
	//�v���C���[�̃C���X�^���X�𐶐�
	m_player = NewGO<Player>(0, "Player");
	//�Q�[���J�����̃C���X�^���X�𐶐�
	m_gameCameraPl = NewGO<GameCameraPl>(0, "GameCameraPl");
	//�X�e�[�W
	//m_stage = NewGO<Stage>(0, "Stage");
	//�f���T�[�N��
	//m_demoCircle = NewGO<DemoCircle>(0, "DemoCircle");

	//�f���{�[��
	//m_demoBall = NewGO<DemoBall>(0, "DemoBall");

	//�T�[�N���`���[�W�̃C���X�^���X�𐶐�
	m_circleCharge = NewGO<CircleCharge>(0, "CircleCharge");
	
	//�I�̃C���X�^���X�𐶐�
	m_bee = NewGO<Bee>(0, "Bee");
	//���x�����\�z
	m_level.Init(L"level/DemoStage2.tkl", [&](LevelObjectData& objData) {
		
		
		if (objData.EqualObjectName(L"Bee") == true) {
           //�I�̃I�u�W�F�N�g
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