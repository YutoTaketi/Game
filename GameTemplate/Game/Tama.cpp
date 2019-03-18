#include "stdafx.h"
#include "Tama.h"


Tama::Tama()
{
}


Tama::~Tama()
{
	DeleteGO(m_skinModelRender);
}

bool Tama::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Tama.cmo");
	m_scale = { 3.0f, 3.0f, 3.0f };
	m_skinModelRender->SetScale(m_scale);
	return true;
}

void Tama::Update()
{
	m_position += m_moveSpeed;
	m_skinModelRender->SetPosition(m_position);
	if (m_timer == 10) {
		DeleteGO(this);
	}
}