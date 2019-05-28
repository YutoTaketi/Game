#include "stdafx.h"
#include "Bee3.h"
#include "Player.h"
#include "Game.h"
#include "Tama.h"

Bee3::Bee3()
{
}


Bee3::~Bee3()
{
	DeleteGO(m_skinModelRender);
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
		CVector3 playerBEE = m_player->m_position - m_position;
		playerBEE.Normalize();
		playerBEE *= 2.0f;
		m_position += playerBEE;


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
	m_player = FindGO<Player>("Player");
	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Bee3::Deth()
{
	if (game == nullptr) {
		game = FindGO<Game>("Game");
	}
	else {
		prefab::CSoundSource* ss;

		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaBee = tama->m_position - m_position;
			if (tamaBee.Length() < 50.0f)
			{

				//エフェクトを作成
				prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
				//エフェクトを再生
				effect->Play(L"effect/Burn.efk");
				CVector3 emitPos = m_position;
				CVector3 emitScale = { 2.0, 2.0, 2.0 };
				effect->SetPosition(emitPos);
				effect->SetScale(emitScale);
				//爆発音を鳴らす
				ss = NewGO<prefab::CSoundSource>(0);
				ss->Init(L"sound/bakuhatu.wav");
				ss->Play(false);
				game->dethCount++;
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
	Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}