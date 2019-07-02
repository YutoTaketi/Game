#include "stdafx.h"
#include "TomboJr.h"
#include "TomboAttack1.h"
#include "Player.h"
#include "Tombo.h"
#include "Game2.h"
#include "Tama.h"


TomboJr::TomboJr()
{
}


TomboJr::~TomboJr()
{
	DeleteGO(m_skinModelRender);
}

bool TomboJr::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/TomboJr.cmo");
	m_scale = { 3.5f, 3.5f, 3.5f };
	return true;
}

void TomboJr::Move()
{
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		playerLen = m_player->m_position - m_position;
		if (playerLen.Length() >= 50) {
			CVector3 playerTomboJr = m_player->m_position - m_position;
			playerTomboJr.Normalize();
			playerTomboJr *= 2.5f;
			m_position += playerTomboJr;

		}


		m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 400) {
			m_position = oldPos;
			m_position.y = 400;
		}
	}
}

void TomboJr::Turn()
{
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}

	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}


void TomboJr::Attack()
{
	AttackTimer++;
	if (AttackTimer == 80) {
		TomboAttack1* attack1 = NewGO<TomboAttack1>(0, "Attack1");
		attack1->m_position = m_position;
		attack1->m_position2 = m_position;
		attack1->m_position.y += 25.0;
		attack1->m_position.y += 60.0;
		attack1->m_rotation = m_rotation;
		attack1->m_rotation2 = m_rotation;
		CVector3 Tombomae = { 0, 0, 1 };
		m_rotation.Apply(Tombomae);
		attack1->m_moveSpeed = Tombomae * 25.0;
		//attack1->m_moveSpeed.y -= 2.0;
		/*if (m_player->m_position.y > m_position.y)
		{
		attack1->m_moveSpeed.y += 3.0;
		}
		else {
		attack1->m_moveSpeed.y -= 2.0;
		}*/

		AttackTimer = 0;
	}
}

void TomboJr::Deth()
{
	if (game2 == nullptr) {
		game2 = FindGO<Game2>("Game2");
	}
	else {
		prefab::CSoundSource* TomboJrDethSS;

		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaBee = tama->m_position - m_position;
			if (tamaBee.Length() < 50.0f)
			{

				//エフェクトを作成
				//prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
				//エフェクトを再生
				/*effect->Play(L"effect/Burn.efk");
				CVector3 emitPos = m_position;
				CVector3 emitScale = { 2.0, 2.0, 2.0 };
				effect->SetPosition(emitPos);
				effect->SetScale(emitScale);*/
				//爆発音を鳴らす
				TomboJrDethSS = NewGO<prefab::CSoundSource>(0);
				TomboJrDethSS->Init(L"sound/TomboJrBakuhatu.wav");
				TomboJrDethSS->SetVolume(2.0);
				TomboJrDethSS->Play(false);

				DeleteGO(this);
				return false;
			}

			return true;
			});


	}

}

void TomboJr::Update()
{
	Move();
	Turn();
	Attack();
	Deth();

	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}