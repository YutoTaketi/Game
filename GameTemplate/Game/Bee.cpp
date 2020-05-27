#include "stdafx.h"
#include "Bee.h"
#include "Player.h"
#include "BeeBallet.h"
#include "Game.h"
#include "Tama.h"
Bee::Bee()
{
}


Bee::~Bee()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("BeeBallet");
}


bool Bee::Start()
{
	
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Bee.cmo");
	m_rotation.SetRotationDeg(CVector3::AxisY, 90.0);
	
	return true;
}

void Bee::Move()
{
	//プレイヤーを追っかける。
	
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		playerLen = m_player->m_position - m_position;
		if (playerLen.Length() >= 50)
		{
			CVector3 playerBEE = m_player->m_position - m_position;
			playerBEE.Normalize();
			playerBEE *= 1.9f;
			m_position += playerBEE;
		}
		
	
		//上昇処理
		m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 600) {
			m_position = oldPos;
			m_position.y = 600;
		}
	}
	
		
}
void Bee::Turn()
{
	//プレイヤーに向けて回転させる。
	 m_player = FindGO<Player>("Player");
	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
	
}

void Bee::BeeAtack()
{
	m_timer++;
	if (m_player == nullptr)
	{
		m_player = FindGO<Player>("Player");
	}
	else {
		if (m_skinModelRender != nullptr)
		{
			if (m_timer == 65) {
				
				//弾を出す
				BeeBallet* beeBallet = NewGO<BeeBallet>(0, "BeeBallet");
				beeBallet->m_position = m_position;
				CVector3 Beemae = { 0, 0, 1 };
				m_rotation.Apply(Beemae);
				beeBallet->m_moveSpeed = Beemae * 30.0;
				if (m_player->m_position.y > m_position.y)
				{
					beeBallet->m_moveSpeed.y += 3.0;
				}
				else {
					beeBallet->m_moveSpeed.y -= 2.0;
				}
				m_timer = 0;
			}
		}
		
		
	}
 	
}


void Bee::Deth()
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
				ss->SetVolume(2.0);
				ss->Play(false);
				game->dethCount++;
				DeleteGO(this);
				return false;
			}

			return true;
		});

	}
	
	
}

void Bee::Update()
{

	Move();
	Turn();
	BeeAtack();
	Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
