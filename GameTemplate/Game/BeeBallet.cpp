#include "stdafx.h"
#include "BeeBallet.h"
#include "Bee.h"


BeeBallet::BeeBallet()
{
}


BeeBallet::~BeeBallet()
{
	DeleteGO(effect);
}

bool BeeBallet::Start()
{
	effect = NewGO<prefab::CEffect>(0);
	//エフェクトを再生
	effect->Play(L"effect/Tama.efk");
	m_scale = { 3.5, 3.5, 3.5 };
	
	
	return true;
}

void BeeBallet::Attack()
{
		bee = FindGO<Bee>("Bee");
		CVector3 Beemae = { 0, 0, 1 };
		bee->m_rotation.Apply(Beemae);
		m_moveSpeed = Beemae * 20.0;
}

void BeeBallet::Update()
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
