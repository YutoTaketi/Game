#include "stdafx.h"
#include "Capsule.h"
#include "Player.h"
#include "Game.h"
#include "CircleCharge.h"


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
		if (m_player == nullptr)
		{
			m_player = FindGO<Player>("Player");
			m_charge = FindGO<CircleCharge>("CircleCharge");
		}
		else
		{
	    get = m_player->m_position - m_position;
		get.Length();
		if (get.Length() < 50.0f) {
			DeleteGO(this);
			m_charge->capsuleget = 1;
		}
		}
	}
	/*if (m_player == nullptr)
	{
		m_player = FindGO<Player>("Player");
	}
	//else
	//{
		CVector3 Capsuleget = m_player->m_position - m_position;
		Capsuleget.Length();
		if (Capsuleget.Length() < 50.0) {
			DeleteGO(this);
			return true;
		}
	//}*/
}

void Capsule::Update()
{
	CapsuleGet();

	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
