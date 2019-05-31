#include "stdafx.h"
#include "Boss.h"
#include "Player.h"
#include "Tama.h"
#include "BossSlash.h"
#include "Game.h"
#include "BossAfterBurn.h"
#include "BossAfterBurnB.h"
#include "BossBall.h"


Boss::Boss()
{
}


Boss::~Boss()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("AfterBurn");
	DeleteGOs("AfterBurnB");
	DeleteGOs("Ball");
	//DeleteGOs("Ball2");
	//DeleteGOs("Ball3");
	//DeleteGOs("Ball4");
	
}

bool Boss::Start()
{
	//�A�j���[�V�����N���b�v�̃��[�h
	m_animationClip[enAnimationClip_Idle].Load(L"animData/Boss/Idle.tka");
	m_animationClip[enAnimationClip_Atack].Load(L"animData/Boss/Atack.tka");
	m_animationClip[enAnimationClip_Boost].Load(L"animData/Boss/Boost.tka");
	//�A�j���[�V�����t���O�ݒ�
	m_animationClip[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClip[enAnimationClip_Atack].SetLoopFlag(false);
	m_animationClip[enAnimationClip_Boost].SetLoopFlag(false);

	//�X�|�[���G�t�F�N�g���쐬
	//�X�|�[���G�t�F�N�g���Đ�
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	//�G�t�F�N�g���Đ��B
	effect->Play(L"effect/BossSporn.efk");
	CVector3 SpornEfPos = m_position;
	CVector3 SpornEfscale = { 7.0, 7.0, 7.0 };
	SpornEfPos.y += 1500.0f;
	effect->SetPosition(SpornEfPos);
	effect->SetScale(SpornEfscale);

	//�{�X�̖������Đ�
	BossNakigoeSS = NewGO<prefab::CSoundSource>(0);
	BossNakigoeSS->Init(L"sound/BossNakigoe.wav");
	BossNakigoeSS->SetVolume(2.0);
	BossNakigoeSS->Play(false);


	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Boss.cmo", m_animationClip, enAnimationClip_num, enFbxUpAxisZ);
	m_position.y = 1500.0;
	m_scale = { 3.5, 3.5, 3.5 };

	BurnEf = NewGO<BossAfterBurn>(0, "AfterBurn");
	
	return true;
}
//�ړ��i�o�[���G�t�F�N�g���Đ��j
void Boss::Move()
{ 
	
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		playerLen = m_player->m_position - m_position;
		if (playerLen.Length() >= 500) {
			CVector3 playerBoss = m_player->m_position - m_position;
			playerBoss.Normalize();
			playerBoss *= 1.5f;
			m_position += playerBoss;

		}
		/*CVector3 playerBoss = m_player->m_position - m_position;
		playerBoss.Normalize();
		playerBoss *= 1.5f;
		m_position += playerBoss;*/

		//m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 400) {
			m_position = oldPos;
			m_position.y = 400;
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
void Boss::Attack()
{
	AttackTime++;
	//�U���̃��L���X�g�^�C��
	//m_skinModelRender->PlayAnimation(enAnimationClip_Atack, 0.0f);
	

  if (life > 300) {
	if (AttackTime == 60) {
		m_skinModelRender->PlayAnimation(enAnimationClip_Atack, 0.0f);
		BossSlash* slash = NewGO<BossSlash>(0, "BossSlash");
		slash->m_position = m_position;
		slash->m_position.y += 100.0;
		slash->m_rotation = m_rotation;
		CVector3 Bossmae = { 0, 0, 1 };
		m_rotation.Apply(Bossmae);
		slash->m_moveSpeed = Bossmae * 25.0;
		slash->m_moveSpeed.y -= 2.0;
		
		AttackTime = 0;
	}
  }

		//���C�t�����ȉ����ƍU�����ς��B
		if (life <= 300) {
			if (AttackTime == 70) {
				CVector3 Bossmae = { 0, 0, 1 };
				m_rotation.Apply(Bossmae);
				bossBall[0] = NewGO<BossBall>(0, "Ball");
				bossBall[0]->m_position = m_position;
				bossBall[0]->m_position.y += 10.0;
				bossBall[0]->m_moveSpeed = Bossmae * 20.0;
				bossBall[0]->m_moveSpeed.y -= 3.0;

				bossBall[1] = NewGO<BossBall>(0, "Ball");
				bossBall[1]->m_position = m_position;
				bossBall[1]->m_position.y += 170.0;
				bossBall[1]->m_moveSpeed = Bossmae * 20.0;
				bossBall[1]->m_moveSpeed.y -= 2.0;

				bossBall[2] = NewGO<BossBall>(0, "Ball");
				bossBall[2]->m_position = m_position;
				bossBall[2]->m_position.x += 90.0;
				bossBall[2]->m_position.y += 100.0;
				bossBall[2]->m_moveSpeed = Bossmae * 30.0;
				bossBall[2]->m_moveSpeed.y -= 3.0;

				bossBall[3] = NewGO<BossBall>(0, "Ball");
				bossBall[3]->m_position = m_position;
				bossBall[3]->m_position.x -= 90.0;
				bossBall[3]->m_position.y += 100.0;
				bossBall[3]->m_moveSpeed = Bossmae * 40.0;
				bossBall[3]->m_moveSpeed.y -= 2.0;
				
				AttackTime = 0;
			}
		}
	
	
}

//��������Ńu�[�X�g
//�{�X�̃��C�t�����ȉ��ɂȂ�����A
//�A�t�^�[�o�[�i�[�̐F���ς��B
void Boss::Boost()
{
	if (life <= 300)
	{
		if (boostHantei == 0) {
			
			DeleteGOs("AfterBurn");
			BurnEfB = NewGO<BossAfterBurnB>(0, "AfterBurnB");
			//��������
			BossNakigoeSS = NewGO<prefab::CSoundSource>(0);
			BossNakigoeSS->Init(L"sound/BossNakigoe.wav");
			BossNakigoeSS->SetVolume(2.0);
			BossNakigoeSS->Play(false);
			boostHantei = 1;
		}
		
	}
}
//��e����
void Boss::Hidan()
{
	
	if (game == nullptr) {
		game = FindGO<Game>("Game");
	}
	else {
		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaBee = tama->m_position - m_position;
			if (tamaBee.Length() < 50.0f)
			{
				//���C�t����
				life -= 17;

				return false;
			}

			return true;
			});

	}
}
//���C�t0�ŏ���
void Boss::Deth()
{
	
	if (game == nullptr)
	{
		game = FindGO<Game>("Game");
	}
	else {
		if (life <= 0)
		{
			game->clearHantei = 1;
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//�f�X�G�t�F�N�g���Đ��B
			effect->Play(L"effect/BossDeth.efk");
			CVector3 DethEfPos = m_position;
			CVector3 DethEfscale = { 0.5, 0.5, 0.5 };
			DethEfPos.y += 10.0f;
			effect->SetPosition(DethEfPos);
			effect->SetScale(DethEfPos);
			//�f�XBGM���Đ�
			prefab::CSoundSource* BossDethS;
			BossDethS = NewGO<prefab::CSoundSource>(0);
			BossDethS->Init(L"sound/BossDeth.wav");
			BossDethS->Play(false);
			DeleteGO(this);
		}

	}
		
}

void Boss::Update()
{
	MoveTimer++;
	if (MoveTimer >= 10) {
		Move();
		Turn();
		Attack();
		Boost();
		
	}
	Hidan();
	Deth();
	//Move();
	//Turn();
	//Attack();
	//Boost();
	//Hidan();
	//Deth();
	m_skinModelRender->SetPosition(m_position);//�{�X
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);

}
