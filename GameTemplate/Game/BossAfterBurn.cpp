#include "stdafx.h"
#include "BossAfterBurn.h"
#include "Boss.h"
#include "Game.h"


BossAfterBurn::BossAfterBurn()
{
}


BossAfterBurn::~BossAfterBurn()
{
	DeleteGOs("AfterBurn");
	
}

bool BossAfterBurn::Start()
{
	
	effect = NewGO<prefab::CEffect>(0, "AfterBurn");
	effect->Play(L"effect/AfterBurn.efk");
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
		m_position.y += 100.0;
		m_rotation = boss->m_rotation;
	}
}


void BossAfterBurn::Update()
{
	Move();
	
	
		effect->SetPosition(m_position);
		effect->SetScale(m_scale);
		effect->SetRotation(m_rotation);
	
}
