#include "stdafx.h"
#include "Player.h"
#include "DemoCircle.h"
#include "Tama.h"
#include "CircleCharge.h"
#include "BeeBallet.h"
#include "PlayerHpBer.h"
#include "Game.h"
#include "GameOver.h"

Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("Tama");
}

bool Player::Start()
{
	//�A�j���[�V�����N���b�v�̃��[�h
	m_animationClip[enAnimationClip_Player_Idle].Load(L"animData/Player/Player_Idle2.tka");
	m_animationClip[enAnimationClip_Player_Shot].Load(L"animData/Player/Player_Shot.tka");
	m_animationClip[enAnimationClip_Player_Jump].Load(L"animData/Player/Player_Jump.tka");
	m_animationClip[enAnimationClip_Player_Run].Load(L"animData/Player/Player_Run.tka");
	/*m_animationClip[enAnimationClip_run].Load(L"animData/unityChan/run.tka");
	m_animationClip[enAnimationClip_jump].Load(L"animData/unityChan/jump.tka");*/
	//���[�v�t���O�̐ݒ�
	m_animationClip[enAnimationClip_Player_Idle].SetLoopFlag(false);
	m_animationClip[enAnimationClip_Player_Shot].SetLoopFlag(true);
	m_animationClip[enAnimationClip_Player_Jump].SetLoopFlag(false);
	m_animationClip[enAnimationClip_Player_Run].SetLoopFlag(true);
	//m_animationClip[enAnimationClip_run].SetLoopFlag(true);
	//m_animationClip[enAnimationClip_jump].SetLoopFlag(false);

	m_charaCon.Init(
		20.0,
		50.0f,
		m_position
	);
	m_normalMap.CreateFromDDSTextureFromFile(L"modelData/PBR_Free_NM.dds");
	m_specularMap.CreateFromDDSTextureFromFile(L"modelData/PBR_Free_MS.dds");
	//�X�L�����f�������_���[���쐬
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//m_skinModelRender->Init(L"modelData/unityChan.cmo", m_animationClip, enAnimationClip_num, enFbxUpAxisY );
	m_skinModelRender->Init(L"modelData/Player.cmo" , m_animationClip, enAnimationClip_num, enFbxUpAxisZ);
	m_skinModelRender->SetShadowCasterFlag(true);
	m_skinModelRender->SetShadowReceiverFlag(true);
	m_skinModelRender->FindMaterial([&](CModelEffect* mat) {
		mat->SetNormalMap(m_normalMap);
		mat->SetSpecularMap(m_specularMap);
		});

	//�N���T�E���h���Đ�
	prefab::CSoundSource* KidouSS;
	KidouSS = NewGO<prefab::CSoundSource>(0);
	KidouSS->Init(L"sound/PlayerKidou.wav");
	KidouSS->SetVolume(0.5);
	KidouSS->Play(false);
	return true;
}



void Player::Move()
{
	//���X�e�B�b�N���͗ʂ������Ƃ�
	float lStick_x = Pad(0).GetLStickXF();
	float lStick_y = Pad(0).GetLStickYF();
	/*if (Pad(0).GetLStickXF() || Pad(0).GetLStickYF())
	{
		if (m_position.y <= 20) {
			WalkTimer++;
			if (WalkTimer == 9) {
				prefab::CSoundSource* WalkSS;
				WalkSS = NewGO<prefab::CSoundSource>(0);
				WalkSS->Init(L"sound/PlayerWalk.wav");
				WalkSS->SetVolume(0.5);
				WalkSS->Play(false);
				WalkTimer = 0;
			}
		}
		
	}*/
	//�J�����̑O�������ƉE�������擾
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ���ʂł̑O�������A�E�����ɕϊ�����B
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();
	//XZ�����̈ړ����x���N���A
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed += cameraForward * lStick_y * 260.0f;
	m_moveSpeed += cameraRight * lStick_x * 260.0f;

	//�W�����v
	if (Pad(0).IsTrigger(enButtonA)
		&& m_charaCon.IsOnGround())
	{
		m_moveSpeed.y = 500.0f;
	}
	else if(Pad(0).GetLStickXF() || Pad(0).GetLStickYF())
	{
		if (m_position.y <= 20) {
			WalkTimer++;
			if (WalkTimer == 9) {
				prefab::CSoundSource* WalkSS;
				WalkSS = NewGO<prefab::CSoundSource>(0);
				WalkSS->Init(L"sound/PlayerWalk.wav");
				WalkSS->SetVolume(0.5);
				WalkSS->Play(false);
				WalkTimer = 0;
			}
		}

	}
	//�L�����N�^�[�R���g���[���[
	m_position = m_charaCon.Execute(m_moveSpeed, GameTime().GetFrameDeltaTime());
}

void Player::Turn()
{
	if (fabsf(m_moveSpeed.x) < 0.001f
		&& fabsf(m_moveSpeed.z) < 0.001f) {
		return;
	}

	float angle = atan2(m_moveSpeed.x, m_moveSpeed.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Player::AnimationController()
{
	if (m_charaCon.IsJump() == false) {
		if (Pad(0).GetLStickXF() || Pad(0).GetLStickYF()) {
			m_skinModelRender->PlayAnimation(enAnimationClip_Player_Run, 0.0f);
		}
		else {
			m_skinModelRender->PlayAnimation(enAnimationClip_Player_Shot, 0.0f);

		}
	}
	if (Pad(0).IsTrigger(enButtonA)) {
		m_skinModelRender->PlayAnimation(enAnimationClip_Player_Jump, 0.0f);
	}
}

//����R2�g���K�[�������ꂽ��A�T�[�N�����o���B
bool Player::CircleSummon()
{
	CircleCharge* ciclecharge = FindGO<CircleCharge>("CircleCharge");
		//����6�ݒu������A�ݒu�ł��Ȃ�
	//����R2�g���K�[�������ꂽ��A�T�[�N�����o���B
	if ( ciclecharge->w > 0 && Pad(0).IsTrigger(enButtonB)) {

		m_demoCircle = NewGO<DemoCircle>(0, "DemoCircle");
		m_demoCircle->m_position.x = m_position.x + 5.0f;
		m_demoCircle->m_position.y = m_position.y + 40.0f;
		m_demoCircle->m_position.z = m_position.z + 5.0f;
		return true;
	}
	else
	{
		return false;
	}
}

void Player::Attack()
{
	

	if (Pad(0).IsTrigger(enButtonRB2)) {
		attacktimer++;
		if (attacktimer == 7) {
			m_tama = NewGO<Tama>(0, "Tama");
			m_tama->m_position = m_position;

			m_tama->m_position.y += 150.0;
			attacktimer = 0;
		}
		/*m_tama = NewGO<Tama>(0, "Tama");
		m_tama->m_position = m_position;
		
		m_tama->m_position.y += 70.0;*/
		
	}
}

void Player::Deth()
{
	/*PlayerHpBer* HpBer = FindGO<PlayerHpBer>("HpBer");
	Game* game = FindGO<Game>("Game");
	if (HpBer->w <= 0)
	{
		NewGO<GameOver>(0, "GameOver");
		//DeleteGO(game);
	}*/
}


void Player::Update()
{
	
	Move();
	Turn();
	AnimationController();
	CircleSummon();
	Attack();
	//Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	
}