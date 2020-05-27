#include "stdafx.h"
#include "TomboAttack1.h"


TomboAttack1::TomboAttack1()
{
}


TomboAttack1::~TomboAttack1()
{
	DeleteGO(effect);
	DeleteGO(effect2);
}

bool TomboAttack1::Start()
{
	effect = NewGO<prefab::CEffect>(0);
	effect2 = NewGO<prefab::CEffect>(0);
	//エフェクトを再生
	effect->Play(L"effect/TomboBeam0.efk");
	m_scale = { 4.0, 4.0, 4.0};

	effect2->Play(L"effect/TomboBeamNemoto.efk");
	m_scale2 = { 4.0, 4.0, 4.0 };
	return true;
}

void TomboAttack1::Update()
{
	//単発ビームのエフェクト
	m_position += m_moveSpeed;

	effect->SetPosition(m_position);
	effect->SetScale(m_scale);
	effect->SetRotation(m_rotation);

	effect2->SetPosition(m_position2);
	effect2->SetScale(m_scale2);
	effect2->SetRotation(m_rotation2);

	m_timer++;
	if (m_timer == 120) {
		DeleteGO(this);
	}
}
