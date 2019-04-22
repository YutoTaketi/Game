#include "stdafx.h"
#include "BeeBallet.h"
#include "Bee.h"


BeeBallet::BeeBallet()
{
}


BeeBallet::~BeeBallet()
{
	DeleteGO(m_skinModelRender);
}

bool BeeBallet::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/BeeBallet.cmo");
	
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
	/*if (bee == nullptr) {
		Attack();
	}*/
	//Attack();
	m_position += m_moveSpeed;
	m_skinModelRender->SetPosition(m_position);
	m_timer++;
	if (m_timer == 120) {
		DeleteGO(this);
	}
}
