#include "stdafx.h"
#include "Koukasasu.h"
#include "Player.h"
#include "KabutoBallet.h"
#include "Game2.h"
#include "Tama.h"


Koukasasu::Koukasasu()
{
}


Koukasasu::~Koukasasu()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("KabutoBallet");
}

bool Koukasasu::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Koukasasu.cmo");
	return true;
}

void Koukasasu::Move()
{
	//プレイヤーに向かって移動
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		StartUp++;
		CVector3 playerBEE = m_player->m_position - m_position;
		playerBEE.Normalize();
		if (StartUp <= 600) {
			playerBEE *= 4.5f;
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

void Koukasasu::Turn()
{
	//プレイヤーに向かって回転
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}

	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Koukasasu::Attack()
{
	m_timer++;
	//プレイヤーに向かって攻撃
	if (m_timer == 80) {
		m_player = FindGO<Player>("Player");
		KabutoBallet* kabutoBallet = NewGO<KabutoBallet>(0, "KabutoBallet");
		kabutoBallet->m_position = m_position;
		CVector3 Bee3mae = { 0, 0, 1 };
		m_rotation.Apply(Bee3mae);
		kabutoBallet->m_moveSpeed = Bee3mae * 20.0;
		
		m_timer = 0;
	}
}

void Koukasasu::Deth()
{
	if (game2 == nullptr) {
		game2 = FindGO<Game2>("Game2");
	}
	else {
		prefab::CSoundSource* ss;

		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaKabuto2 = tama->m_position - m_position;
			if (tamaKabuto2.Length() < 50.0f)
			{

				//エフェクトを作成
				prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
				//エフェクトを再生
				effect->Play(L"effect/KabutoDeth.efk");
				CVector3 emitPos = m_position;
				CVector3 emitScale = { 2.0, 2.0, 2.0 };
				effect->SetPosition(emitPos);
				effect->SetScale(emitScale);
				//爆発音を鳴らす
				ss = NewGO<prefab::CSoundSource>(0);
				ss->Init(L"sound/KabutoBakuhatu.wav");
				ss->SetVolume(2.0);
				ss->Play(false);
				game2->KabutoDethCount++;
				DeleteGO(this);
				return false;
			}
			return true;
			});

	}

}

void Koukasasu::Update()
{
	Move();
	Turn();
	Attack();
	Deth();

	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
