#include "stdafx.h"
#include "TomboAttack2.h"


TomboAttack2::TomboAttack2()
{
}


TomboAttack2::~TomboAttack2()
{
	DeleteGO(effect);
}

bool TomboAttack2::Start()
{
	effect = NewGO<prefab::CEffect>(0);
	effect->Play(L"effect/TomboBeam0.efk");
	m_scale = { 6.0, 6.0, 10.0 };
	return true;
}

void TomboAttack2::Update()
{
	effect->SetPosition(m_position);
	effect->SetRotation(m_rotation);
	effect->SetScale(m_scale);

	m_timer++;
	if (m_timer == 120) {
		DeleteGO(this);
	}
}
