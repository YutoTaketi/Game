#include "stdafx.h"
#include "Tombo.h"
#include "Player.h"
#include "TomboAttackState.h"
#include "TomboAttack1.h"
#include "TomboAttack2.h"
#include "Tama.h"
#include "Game2.h"


Tombo::Tombo()
{
}


Tombo::~Tombo()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("Attack1");
	DeleteGOs("Attack2");
}

bool Tombo::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Tombo.cmo");
	m_scale = { 3.0f, 3.0f, 3.0f };
	return true;
}

void Tombo::Move()
{
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		playerLen = m_player->m_position - m_position;
		if (playerLen.Length() >= 50) {
			CVector3 playerKabuto = m_player->m_position - m_position;
			playerKabuto.Normalize();
			playerKabuto *= 1.5f;
			m_position += playerKabuto;

		}


		m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 400) {
			m_position = oldPos;
			m_position.y = 400;
		}
	}
}

void Tombo::Turn()
{
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}

	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Tombo::Attack()
{
	tomboAttackState = &TomboAttackState::GetInstance();
	if (tomboAttackState->GetAttackNumber() == TomboAttackState::enState_Attack1)
	{
		AttackTimer++;
		if (AttackTimer == 70) {
			/*TomboAttack1* attack1 = NewGO<TomboAttack1>(0, "Attack1");
			attack1->m_position = m_position;
			attack1->m_position2 = m_position;
			attack1->m_position.y += 25.0;
			attack1->m_position.y += 60.0;
			attack1->m_rotation = m_rotation;
			attack1->m_rotation2 = m_rotation;
			CVector3 Tombomae = { 0, 0, 1 };
			m_rotation.Apply(Tombomae);
			attack1->m_moveSpeed = Tombomae * 25.0;*/
			//attack1->m_moveSpeed.y -= 2.0;
			/*if (m_player->m_position.y > m_position.y)
			{
				attack1->m_moveSpeed.y += 3.0;
			}
			else {
				attack1->m_moveSpeed.y -= 2.0;
			}*/

			//AttackTimer = 0;

			
		}
	}

	/*if (tomboAttackState->GetAttackNumber() == TomboAttackState::enState_Attack2)
	{
	  TomboAttack2* attack2 = NewGO<TomboAttack2>(0, "Attack2");
			attack2->m_position = m_position;
			attack2->m_position.y += 25.0;
			attack2->m_rotation = m_rotation;
			CVector3 Tombomae = { 0, 0, 1 };
			m_rotation.Apply(Tombomae);
			attack2->m_moveSpeed = Tombomae * 1.0; 
			AttackTimer = 0;
	}*/

	/*if (tomboAttackState->GetAttackNumber() == TomboAttackState::enState_Attack3) {

	}*/
}

//一定時間経過後
//分身する
void Tombo::Bunsin()
{

}

void Tombo::Hidan()
{
	if (game2 == nullptr) {
		game2 = FindGO<Game2>("Game2");
	}
	else {
		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaTombo = tama->m_position - m_position;
			if (tamaTombo.Length() < 50.0f)
			{
				//ライフ減少
				Life -= 500;

				return false;
			}

			return true;
		});

	}
}

void Tombo::Deth()
{

	if (Life == 0) {
		DeleteGO(this);
	}
	
}

void Tombo::Update()
{
	Move();
	Turn();
	Attack();
	Hidan();
	Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
