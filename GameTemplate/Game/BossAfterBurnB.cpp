#include "stdafx.h"
#include "BossAfterBurnB.h"
#include "Boss.h"
#include "Game.h"

BossAfterBurnB::BossAfterBurnB()
{
}


BossAfterBurnB::~BossAfterBurnB()
{
	DeleteGO(effect);
}

bool BossAfterBurnB::Start()
{
	effect = NewGO<prefab::CEffect>(0, "AfterBurnB");
	effect->Play(L"effect/AftarBurnB.efk");
	m_scale = { 3.0, 3.0, 4.0 };
	return true;
}

void BossAfterBurnB::Move()
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
}

void BossAfterBurnB::Update()
{
	Move();
	effect->SetPosition(m_position);
	effect->SetScale(m_scale);
	effect->SetRotation(m_rotation);

}
