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
#include "Boss.h"   
#include "Capsule.h"
#include "SpornSinden.h"
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
	DeleteGOs("SpornSinden");
	DeleteGOs("HpBer");
	DeleteGOs("CircleCharge");
	DeleteGO(m_bgmSoundSource);
	DeleteGO(m_directionLig);
	//DeleteGO(m_level);
	
}
bool Game::Start()
{
	//�v���C���[�̃C���X�^���X�𐶐�
	m_player = NewGO<Player>(0, "Player");
	//�Q�[���J�����̃C���X�^���X�𐶐�
	m_gameCameraPl = NewGO<GameCameraPl>(0, "GameCameraPl");
	//���s������ݒ肷��B
	m_directionLig = NewGO<prefab::CDirectionLight>(0);
	m_directionLig->SetDirection({ 0.707f, -0.707f, 0.0f });
	m_directionLig->SetColor({10.0f, 10.0f, 10.0f, 1.0f});

	GraphicsEngine().GetShadowMap().SetLightDirection({ 0.707f, -0.707f, 0.0f });

	//�T�[�N���`���[�W�̃C���X�^���X�𐶐�
	m_circleCharge = NewGO<CircleCharge>(0, "CircleCharge");
	//�v���C���[��HP�o�[��\��
	m_HpBer = NewGO<PlayerHpBer>(0, "HpBer");
	
	/

	gameSS = NewGO<prefab::CSoundSource>(0);
	gameSS->Init(L"sound/GameSoundDemo.wav");
	gameSS->SetVolume(0.7);
	gameSS->Play(true);
	////�I�̃C���X�^���X�𐶐�
	//m_bee = NewGO<Bee>(0, "Bee");
	//���x�����\�z
	m_level.Init(L"level/Stage1.tkl", [&](LevelObjectData& objData) {
		
		if (objData.EqualObjectName(L"Bee") == true) {
			//�I�̃I�u�W�F�N�g
			Bee* bee = NewGO<Bee>(0, "Bee");
			bee->m_position = objData.position;
			bee->m_rotation = objData.rotation;
			bee->m_scale = objData.scale;
			return true;
		}
		

		else if (objData.EqualObjectName(L"Bee2") == true) {
			//�I�̃I�u�W�F�N�g
			Bee2* bee2 = NewGO<Bee2>(0, "Bee2");
			bee2->m_position = objData.position;
			bee2->m_rotation = objData.rotation;
			bee2->m_scale = objData.scale;
			return true;
		}
		
		else if (objData.EqualObjectName(L"Capsule") == true) {
			//�J�v�Z���̃C���X�^���X�𐶐�
			Capsule* capsule = NewGO<Capsule>(0, "Capsule");
			capsule->m_position = objData.position;
			capsule->m_rotation = objData.rotation;
			capsule->m_scale = objData.scale;
			return true;
		}

		else if (objData.EqualObjectName(L"SpornSinden") == true) {
			//�X�|�[���_�a�̃C���X�^���X�𐶐�
			SpornSinden* spornSinden = NewGO<SpornSinden>(0, "SpornSinden");
			spornSinden->m_position = objData.position;
			spornSinden->m_rotation = objData.rotation;
			spornSinden->m_scale = objData.scale;
			return true;
		}

		return false;
		
	});
	return true;
}

void Game::Update()
{
	//Bee����萔�|������Boss(�J�}�L��)�o��
	if (dethCount == 10) {
	  if (BossFlag == 0) {
		m_boss = NewGO<Boss>(0, "Boss");
		BossFlag = 1;
		}
	  //�{�X�o�g��BGM�ɐ؂�ւ��
	}

	
	//�N���A��ʂɈڂ�
	if ( clearHantei == 1)
	{ 
		gameEndTimer++;
		if (gameEndTimer == 200) {
			NewGO<GameClear>(0, "GameClear");
			DeleteGO(this);
			DeleteGO(gameSS);
			BossFlag = 0;
			dethCount = 0;
		}
		
	}
	//�Q�[���I�[�o�[��ʂɈڂ�
	PlayerHpBer* HpBer = FindGO<PlayerHpBer>("HpBer");
	if (HpBer->w <= 0 && clearHantei == 0)
	{
		NewGO<GameOver>(0, "GameOver");
		DeleteGO(this);
		DeleteGO(gameSS);
		BossFlag = 0;
		dethCount = 0;
	}
}