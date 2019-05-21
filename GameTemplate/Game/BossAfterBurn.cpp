#include "stdafx.h"
#include "BossAfterBurn.h"
#include "Boss.h"
#include "Game.h"


BossAfterBurn::BossAfterBurn()
{
}


BossAfterBurn::~BossAfterBurn()
{
	DeleteGO(effect);
}

bool BossAfterBurn::Start()
{
	
	effect = NewGO<prefab::CEffect>(0);
	effect->Play(L"effect/AfterBurn.efk");
	m_position;
	m_scale = { 3.0, 3.0, 4.0 };
	return true;
}

void BossAfterBurn::Move()
{
	if (boss == nullptr) {
		game = FindGO<Game>("Game");
		boss = FindGO<Boss>("Boss");
	}
	else {
		m_position = boss->m_position;
		m_position.y += 110.0;


		m_rotation = boss->m_rotation;
	}
	
	 /*game = FindGO<Game>("Game");
	 boss = FindGO<Boss>("Boss");
	m_position = boss->m_position;
	m_position.y += 110.0;
	m_position.z -= 130.0;

	m_rotation = boss->m_rotation;*/
	//CVector3 TurnEf = m_position - boss->m_position;
	//float angle = atan2(TurnEf.x, TurnEf.z);
	//m_rotation.SetRotation(CVector3::AxisY, angle);
	//m_rotation.SetRotationDeg(CVector3::AxisZ, -180.0);
}

void BossAfterBurn::Update()
{
	Move();
	effect->SetPosition(m_position);
	effect->SetScale(m_scale);
	effect->SetRotation(m_rotation);
}
