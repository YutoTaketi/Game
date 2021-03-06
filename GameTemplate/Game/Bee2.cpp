#include "stdafx.h"
#include "Bee2.h"
#include "Player.h"
#include "Game.h"
#include "BeeBallet.h"
#include "Tama.h"


Bee2::Bee2()
{
}


Bee2::~Bee2()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("BeeBallet");
}

bool Bee2::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Bee2.cmo");
	m_rotation.SetRotationDeg(CVector3::AxisY, 90.0);

	return true;
}

void Bee2::Move()
{
	//プレイヤーを追っかける。

	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		playerLen = m_player->m_position - m_position;
		if (playerLen.Length() >= 1000) {
			CVector3 playerBEE = m_player->m_position - m_position;
			playerBEE.Normalize();
			playerBEE *= 2.5f;
			m_position += playerBEE;

		}
		else {
			moveTimer++;
			if (moveTimer <= 80 && moveState == 0) {
				m_position.x++;
		    }
			else if (moveTimer > 80 && moveState ==0){
				moveState = 1;
				moveTimer = 0;
			}
			if (moveTimer <= 80 && moveState == 1)
			{
				m_position.x--;
			}
			else if (moveTimer > 80 && moveState == 1){
				moveState = 0;
				moveTimer = 0;
			}
		}
		
	
		m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 400) {
			m_position = oldPos;
			m_position.y = 400;
		}
	}
	
}

void Bee2::Turn()
{
	//プレイヤーに向けて回転させる
	m_player = FindGO<Player>("Player");
	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Bee2::BeeAtack()
{
	m_timer++;
	if (m_skinModelRender != nullptr)
	{
		//弾を出す
		if (m_timer == 60) {
			m_player = FindGO<Player>("Player");
			BeeBallet* beeBallet = NewGO<BeeBallet>(0, "BeeBallet");
			beeBallet->m_position = m_position;
			CVector3 Beemae = { 0, 0, 1 };
			m_rotation.Apply(Beemae);
			beeBallet->m_moveSpeed = Beemae * 20.0;
			
			m_timer = 0;
		}
	}
}
	

void Bee2::Deth()
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

void Bee2::Update()
{
	m_player = FindGO<Player>("Player");
	CVector3 PlayertonoKyori = m_player->m_position - m_position;
	if (PlayertonoKyori.Length() < 1500)
	{
		//プレイヤーとの距離が近くなったら動き出す。
		Move();
		Turn();
		BeeAtack();
		Deth();
	}
	

	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
