#include "stdafx.h"
#include "DemoCircle.h"
#include "Player.h"


DemoCircle::DemoCircle()
{
}


DemoCircle::~DemoCircle()
{
	DeleteGO(m_skinModelRender);
}

bool DemoCircle::Start()
{
	
    m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/DemoCircle.cmo");
	//m_position = { 0.0f, 15.0f, 300.0f };
	
	return true;
}

void DemoCircle::Update()
{
	m_timer++;
	m_player = FindGO<Player>("Player");
	//m_positon = m_player->m_position;
	m_skinModelRender->SetPosition(m_position);
	CVector3 Floatplayer = m_position - m_player->m_position;
	if (Floatplayer.Length() < 50.0f)
	{
		m_player->m_moveSpeed.y = 1000.0f;
	}

	if (m_timer == 150) {
		DeleteGO(this);
		m_timer = 0;
	}
}