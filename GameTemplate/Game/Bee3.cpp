#include "stdafx.h"
#include "Bee3.h"
#include "Player.h"
#include "Game.h"
#include "Tama.h"
#include "Bee3Ballet.h"

Bee3::Bee3()
{
}


Bee3::~Bee3()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("Bee3Ballet");
}

bool Bee3::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Bee3.cmo");
	return true;
}

void Bee3::Move()
{
	//プレイヤーを追っかける。

	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		StartUp++;
		CVector3 playerBEE = m_player->m_position - m_position;
		playerBEE.Normalize();
		if (StartUp <= 300) {
			playerBEE *= 5.0f;
			m_position += playerBEE;
		}
		else {
			playerBEE *= 2.0f;
			m_position += playerBEE;
		}
		


		m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 400) {
			m_position = oldPos;
			m_position.y = 400;
		}
	}
}

void Bee3::Turn()
{
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	
	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Bee3::Attack()
{
	m_timer++;

	if (m_timer == 80) {
		m_player = FindGO<Player>("Player");
		Bee3Ballet* bee3Ballet = NewGO<Bee3Ballet>(0, "Bee3Ballet");
		bee3Ballet->m_position = m_position;
		CVector3 Bee3mae = { 0, 0, 1 };
		m_rotation.Apply(Bee3mae);
		bee3Ballet->m_moveSpeed = Bee3mae * 20.0;
		if (m_player->m_position.y > m_position.y)
		{
			bee3Ballet->m_moveSpeed.y += 3.0;
		}
		else {
			bee3Ballet->m_moveSpeed.y -= 2.0;
		}
		m_timer = 0;
	}
}

void Bee3::Deth()
{
	if (game == nullptr) {
		game = FindGO<Game>("Game");
	}
	else {
		prefab::CSoundSource* Bee3dethss;

		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaBee3 = tama->m_position - m_position;
			if (tamaBee3.Length() < 50.0f)
			{

				//エフェクトを作成
				 effect = NewGO<prefab::CEffect>(0);
				//エフェクトを再生
				effect->Play(L"effect/Burn.efk");
				CVector3 dethEFPos = m_position;
				CVector3 dethEFScale = { 2.0, 2.0, 2.0 };
				effect->SetPosition(dethEFPos);
				effect->SetScale(dethEFScale);
				//爆発音を鳴らす
				Bee3dethss = NewGO<prefab::CSoundSource>(0);
				Bee3dethss->Init(L"sound/bakuhatu.wav");
				Bee3dethss->SetVolume(2.0);
				Bee3dethss->Play(false);
				Bee3dethCount += 1;
				DeleteGO(this);
				return false;
			}

			return true;
		});
	}
}

void Bee3::Update()
{
	Move();
	Turn();
	Attack();
	Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}