#include "stdafx.h"
#include "BeeBallet.h"


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

void BeeBallet::Update()
{
	m_position += m_moveSpeed;
	m_skinModelRender->SetPosition(m_position);
	m_timer++;
	if (m_timer == 3) {
		DeleteGO(this);
	}
}
