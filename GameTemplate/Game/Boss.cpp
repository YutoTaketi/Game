#include "stdafx.h"
#include "Boss.h"
#include "Player.h"
#include "Tama.h"
#include "Game.h"


Boss::Boss()
{
}


Boss::~Boss()
{
	DeleteGO(m_skinModelRender);
}

bool Boss::Start()
{
	//�A�j���[�V�����N���b�v�̃��[�h
	
	m_animationClip[enAnimationClip_Atack].Load(L"animData/Boss/Atack.tka");
	m_animationClip[enAnimationClip_Boost].Load(L"animData/Boss/Boost.tka");
	//�A�j���[�V�����t���O�ݒ�
	m_animationClip[enAnimationClip_Atack].SetLoopFlag(false);
	m_animationClip[enAnimationClip_Boost].SetLoopFlag(false);

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Boss.cmo", m_animationClip, enAnimationClip_num, enFbxUpAxisZ);
	m_position.y = 800.0;
	m_scale = { 2.0, 2.0, 2.0 };
	return true;
}
//�ړ��i�o�[���G�t�F�N�g���Đ��j
void Boss::Move()
{ 
	
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		CVector3 playerBoss = m_player->m_position - m_position;
		playerBoss.Normalize();
		playerBoss *= 3.0f;
		m_position += playerBoss;

		//m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 100) {
			m_position = oldPos;
			m_position.y = 300;
		}
	}


}
//�^�[��
void Boss::Turn()
{
	
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		CVector3 playerBEE = m_player->m_position - m_position;
		float angle = atan2(playerBEE.x, playerBEE.z);
		m_rotation.SetRotation(CVector3::AxisY, angle);
	}
}
//�U��
void Boss::Atack()
{
	//�U���̃��L���X�g�^�C��
	//m_skinModelRender->PlayAnimation(enAnimationClip_Atack, 0.0f);
}

//��������Ń^�[�{�i�^�C�}�[����ɂ��邩�͖��� �o�[���G�t�F�N�g�i�j�j
//�v���C���[�Ƃ̋��������ȏ㗣�ꂽ��
void Boss::Boost()
{
}
//��e����
void Boss::Hidan()
{
	Game* game = nullptr;
	if (game == nullptr) {
		game = FindGO<Game>("Game");
		
		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaBee = tama->m_position - m_position;
			if (tamaBee.Length() < 50.0f)
			{
				//���C�t����
				life -= 10;

				return false;
			}

			return true;
			});

	}
}
//���C�t0�ŏ���
void Boss::Deth()
{
	Game* game = nullptr;
	if (game == nullptr)
	{
		game = FindGO<Game>("Game");
		if (life == 0)
		{
			game->clearHantei = 1;
			DeleteGO(this);
		}
		
	}
	
}

void Boss::Update()
{
	//Move();
	//Turn();
	Hidan();
	Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
