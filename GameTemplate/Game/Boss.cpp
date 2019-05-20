#include "stdafx.h"
#include "Boss.h"
#include "Player.h"
#include "Tama.h"
#include "BossSlash.h"
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
	SpornEfPos.y += 800.0f;
	effect->SetPosition(SpornEfPos);
	effect->SetScale(SpornEfscale);

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Boss.cmo", m_animationClip, enAnimationClip_num, enFbxUpAxisZ);
	m_position.y = 800.0;
	m_scale = { 2.0, 2.0, 2.0 };

	StartEf();
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

void Boss::StartEf()
{
	//�G�t�F�N�g���쐬
	effect = NewGO<prefab::CEffect>(0);
	effect->Play(L"effect/AfterBurn.efk");
	emitPos = m_position;
	emitPos.y += 110.0;
	emitPos.z -= 130.0;
	 emitScale = { 3.0, 3.0, 4.0 };
	
	
	
}

//�G�t�F�N�g�̈ړ�(AftarBurn)
void Boss::MoveEf()
{
	CVector3 BurnEf = m_position - emitPos;
	BurnEf.Normalize();
	BurnEf *= 3.0f;
	emitPos += BurnEf;
	//emitPos.y += 110.0;
	emitPos.y = m_position.y+110.0;
	
	//��]
	emitRot.SetRotationDeg(CVector3::AxisY, 0.0);
	CVector3 TurnEf = m_position - emitPos;
	float angle = atan2(TurnEf.x, TurnEf.z);
	emitRot.SetRotation(CVector3::AxisY, angle);

	//effect->SetPosition(emitPos);
	//effect->SetRotation(emitRot);
}

//�U��
void Boss::Attack()
{
	AttackTime++;
	//�U���̃��L���X�g�^�C��
	//m_skinModelRender->PlayAnimation(enAnimationClip_Atack, 0.0f);
	if (AttackTime == 60) {
		m_skinModelRender->PlayAnimation(enAnimationClip_Atack, 0.0f);
		BossSlash* slash = NewGO<BossSlash>(0, "BossSlash");
		slash->m_position = m_position;
		slash->m_position.y += 100.0;
		CVector3 Bossmae = { 0, 0, 1 };
		m_rotation.Apply(Bossmae);
		slash->m_moveSpeed = Bossmae * 20.0;

		AttackTime = 0.0f;
	}
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
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//�f�X�G�t�F�N�g���Đ��B
			effect->Play(L"effect/BossDeth.efk");
			CVector3 DethEfPos = m_position;
			DethEfPos.y += 10.0f;
			effect->SetPosition(DethEfPos);
			DeleteGO(this);
		}
		
	}
	
}

void Boss::Update()
{
	//Move();
	//Turn();
	//MoveEf();
	Attack();
	//Hidan();
	//Deth();
	m_skinModelRender->SetPosition(m_position);//�{�X
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);

	effect->SetPosition(emitPos);    //�G�t�F�N�g
	effect->SetRotation(emitRot);
	effect->SetScale(emitScale);
}
