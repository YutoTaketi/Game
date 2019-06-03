#include "stdafx.h"
#include "Capsule.h"
#include "Player.h"
#include "Game.h"
#include "CircleCharge.h"
#include "PlayerHpBer.h"


Capsule::Capsule()
{
}


Capsule::~Capsule()
{
	DeleteGO(m_skinModelRender);
}

bool Capsule::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Capsule.cmo");
	return true;
}

void Capsule::CapsuleGet()
{
	Game* game = nullptr;
	if (game == nullptr)
	{
		game = FindGO<Game>("Game");
		m_player = FindGO<Player>("Player");
		m_charge = FindGO<CircleCharge>("CircleCharge");
		hpBer = FindGO<PlayerHpBer>("HpBer");
		if (m_player == nullptr)
		{
			//m_player = FindGO<Player>("Player");
			//m_charge = FindGO<CircleCharge>("CircleCharge");
		}
		else
		{
	    get = m_player->m_position - m_position;
		get.Length();
		if (get.Length() < 80.0f) {
			prefab::CSoundSource* CapsulegetSS;
			CapsulegetSS = NewGO<prefab::CSoundSource>(0);
			CapsulegetSS->Init(L"sound/circleCharge.wav");
			CapsulegetSS->SetVolume(1.0);
			CapsulegetSS->Play(false);
			DeleteGO(this);
			m_charge->capsuleget = 1;
		}
		}
	}
	
}

void Capsule::Update()
{
	CapsuleGet();

	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
