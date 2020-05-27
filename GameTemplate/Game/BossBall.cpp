#include "stdafx.h"
#include "BossBall.h"


BossBall::BossBall()
{
}


BossBall::~BossBall()
{
	DeleteGO(effect);
}

bool BossBall::Start()
{
	effect = NewGO<prefab::CEffect>(0);
	//エフェクトを再生
	effect->Play(L"effect/BollAttack.efk");
	m_scale = { 3.5, 3.5, 3.5 };
	return true;
}

void BossBall::Update()
{
	m_position += m_moveSpeed;
	effect->SetPosition(m_position);
	effect->SetScale(m_scale);
	m_timer++;
	//消滅
	if (m_timer == 120) {
		DeleteGO(this);
	}
}
