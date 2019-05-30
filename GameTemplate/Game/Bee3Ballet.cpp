#include "stdafx.h"
#include "Bee3Ballet.h"


Bee3Ballet::Bee3Ballet()
{
}


Bee3Ballet::~Bee3Ballet()
{
	DeleteGO(effect);
}

bool Bee3Ballet::Start()
{
	effect = NewGO<prefab::CEffect>(0);
	//エフェクトを再生
	effect->Play(L"effect/Bee3Tama.efk");
	m_scale = { 3.0, 3.0, 3.0 };
	return true;
}

void Bee3Ballet::Update()
{
	m_position += m_moveSpeed;
	m_position.y -= 5.0;
	effect->SetPosition(m_position);
	effect->SetScale(m_scale);
	effect->SetRotation(m_rotation);

	m_timer++;
	if (m_timer == 120) {
		DeleteGO(this);
	}
}
