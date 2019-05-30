#include "stdafx.h"
#include "SpornSinden.h"
#include "Game.h"
#include "Bee3.h"

SpornSinden::SpornSinden()
{
}


SpornSinden::~SpornSinden()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("Bee3");
}

bool SpornSinden::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/SpornSinden.cmo");
	return true;
}

void SpornSinden::BeeSporn()
{
	//もしボスが出現したらBee3が出てくる
	if (game == nullptr) {
		game = FindGO<Game>("Game");
	}
	else {
		if (game->BossFlag == 1)
		{
			SpornTimer++;
			
				if (SpornTimer == 80 +i && spornCount <= 2) {
					bee3 = NewGO<Bee3>(0, "Bee3");
					bee3->m_position = m_position;
					bee3->m_position.y += 900.0;
					spornCount += 1;
					SpornTimer = 0;
					i += 200;
				}
				
			
		}
	}
}

void SpornSinden::Update()
{
	BeeSporn();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
	//m_phyStaticObject->CreateCommon( m_position, m_rotation);
}