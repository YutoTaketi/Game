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
}


bool Bee::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Bee.cmo");
	m_rotation.SetRotationDeg(CVector3::AxisY, 90.0);
	//BeeAtack();
	
	return true;
}

void Bee::Move()
{
	//プレイヤーを追っかける。
	Player* player = FindGO<Player>("Player");
	CVector3 playerBEE = player->m_position - m_position;
	playerBEE.Normalize();
	m_position += playerBEE * 2.0;
	CVector3 oldPos = m_position;
	if (m_position.y <= 100) {
		m_position = oldPos;
		m_position.y = 200;
	}
	
}
void Bee::Turn()
{
	Player* player = FindGO<Player>("Player");
	CVector3 playerBEE = player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);

	/*if (fabsf(m_position.x) < 0.001f
		&& fabsf(m_position.z) < 0.001f) {
		return;
	}

	float angle = atan2(m_position.x, m_position.z);
	m_rotation.SetRotation(CVector3::AxisY, angle+90);*/
	
}

void Bee::BeeAtack()
{
	m_timer++;
	
	
	
 	if (m_timer = 50) {
		
		BeeBallet* beeBallet = NewGO<BeeBallet>(0, "BeeBallet");
		beeBallet->m_position = m_position;
		
		m_timer = 0.0f;
	}
}

void Bee::Deth()
{
	Game* game = FindGO<Game>("Game");
	//Bee* bee = FindGO<Bee>("Bee");
	//if (bee != nullptr) {
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
				DeleteGO(this);
			}
			
			return true;
		});
	//}
	
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
