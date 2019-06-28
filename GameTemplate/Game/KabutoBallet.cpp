#include "stdafx.h"
#include "KabutoBallet.h"


KabutoBallet::KabutoBallet()
{
}


KabutoBallet::~KabutoBallet()
{
	DeleteGO(effect);
}

bool KabutoBallet::Start()
{
	effect = NewGO<prefab::CEffect>(0);
	effect->Play(L"effect/KabutoBall.efk");
	m_scale = { 4.0, 4.0, 4.0 };
	return true;
}

void KabutoBallet::Update()
{
	m_position += m_moveSpeed;
	effect->SetPosition(m_position);
	effect->SetRotation(m_rotation);
	effect->SetScale(m_scale);
	m_timer++;
	if (m_timer == 120) {
		DeleteGO(this);
	}
}
