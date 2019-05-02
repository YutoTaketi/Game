#include "stdafx.h"
#include "Capsule.h"


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

void Capsule::Update()
{


	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
