#include "stdafx.h"
#include "TomboAttack2.h"
#include "Player.h"
#include "Tombo.h"


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
	effect->Play(L"effect/TomboBeam.efk");
	m_scale = { 8.0, 8.0, 10.0 };
	prefab::CSoundSource* HiBeamss;
	HiBeamss = NewGO<prefab::CSoundSource>(0);
	HiBeamss->Init(L"sound/TomboHiBeam.wav");
	HiBeamss->SetVolume(2.0);
	HiBeamss->Play(false);
	return true;
}

void TomboAttack2::Update()
{
	//プレイヤーの位置がトンボよりも下なら、
	//斜め下にする
	Player* player = FindGO<Player>("Player");
	Tombo* tombo = FindGO<Tombo>("Tombo");
	if (tombo->m_position.y >= player->m_position.y) {
		m_rotation.SetRotation(CVector3::AxisZ, -30.0);
	}
	effect->SetPosition(m_position);
	effect->SetRotation(m_rotation);
	effect->SetScale(m_scale);

	m_timer++;
	if (m_timer == 240) {
		DeleteGO(this);
	}
}
