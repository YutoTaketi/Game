#include "stdafx.h"
#include "CircleCharge.h"


CircleCharge::CircleCharge()
{
}


CircleCharge::~CircleCharge()
{
	DeleteGO(m_spriteRender);
}

bool CircleCharge::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/hpmp_bar.dds",250, 90);
	m_position = { 380.0, -250.0, 0.0 };
	m_spriteRender->SetPosition(m_position);

	return true;
}

void CircleCharge::Update()
{

}
