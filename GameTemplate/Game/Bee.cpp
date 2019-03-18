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
	
	//m_position = { 300.0, 80.0, 0.0 };
	//m_skinModelRender->SetPosition(m_position);
	return true;
}

void Bee::Move()
{
	//プレイヤーを追っかける。
	Player* player = FindGO<Player>("Player");
	CVector3 playerBEE = player->m_position - m_position;
	playerBEE.Normalize();
	m_position += playerBEE * 1.0;
	CVector3 oldPos = m_position;
	if (m_position.y <= 100) {
		m_position = oldPos;
		m_position.y = 500;
	}
	
}
void Bee::Turn()
{
	if (fabsf(m_position.x) < 0.001f
		&& fabsf(m_position.z) < 0.001f) {
		return;
	}

	float angle = atan2(m_position.x, m_position.z);
	m_rotation.SetRotation(CVector3::AxisY, -angle);
}

void Bee::BeeAtack()
{
	m_timer++;
	if (m_timer = 30) {
		BeeBallet* beeBallet = NewGO<BeeBallet>(0, "BeeBallet");
		beeBallet->m_position = m_position;
		beeBallet->m_moveSpeed.z = 50.0;
		m_timer = 0.0f;
	}
}

void Bee::Deth()
{
	Game* game = FindGO<Game>("Game");
	Bee* bee = FindGO<Bee>("Bee");
	if (bee != nullptr) {
		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaBee = tama->m_position - m_position;
			if (tamaBee.Length() < 50.0f)
			{
				DeleteGO(this);
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
