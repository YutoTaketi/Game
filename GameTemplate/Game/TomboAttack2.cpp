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
	DeleteGOs("HiBeamSS");
	DeleteGOs("NakigoeSS");

}

bool TomboAttack2::Start()
{
	effect = NewGO<prefab::CEffect>(0);
	effect->Play(L"effect/TomboBeam.efk");
	m_scale = { 8.0, 8.0, 10.0 };
	prefab::CSoundSource* HiBeamss;
	HiBeamss = NewGO<prefab::CSoundSource>(0, "HiBeamSS");
	HiBeamss->Init(L"sound/TomboHiBeam.wav");
	HiBeamss->SetVolume(2.0);
	HiBeamss->Play(false);
	//鳴き声
	prefab::CSoundSource* tomboNakigoeSS;
	tomboNakigoeSS = NewGO<prefab::CSoundSource>(0, "NakigoeSS");
	tomboNakigoeSS->Init(L"sound/TomboNakigoe.wav");
	tomboNakigoeSS->SetVolume(2.0);
	tomboNakigoeSS->Play(false);
	return true;
}

void TomboAttack2::Update()
{
	//プレイヤーの位置がトンボよりも下なら、
	//斜め下にする
	//プレイヤーを追従
	Player* player = FindGO<Player>("Player");
	Tombo* tombo = FindGO<Tombo>("Tombo");
	
	CVector3 Tombomae = { 0, 0, 1 };
	m_rotation.Apply(Tombomae);
	m_moveSpeed = Tombomae * 1.0;
	//プレイヤーに向ける
	if (tombo->m_position.y >= player->m_position.y) {
		CVector3 tomboPlayer = tombo->m_position - player->m_position;
		CVector3 EFmae = { 0.0f, 0.0f, -1.0f };
		tomboPlayer.Normalize();
		m_rotation.SetRotation(EFmae,tomboPlayer);
	}
	effect->SetPosition(m_position);
	effect->SetRotation(m_rotation);
	effect->SetScale(m_scale);

	m_timer++;
	if (m_timer == 120) {
		DeleteGO(this);
	}
}
