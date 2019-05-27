#include "stdafx.h"
#include "SpornSinden.h"


SpornSinden::SpornSinden()
{
}


SpornSinden::~SpornSinden()
{
}

bool SpornSinden::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/SpornSinden.cmo");
	return true;
}

void SpornSinden::Update()
{
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}