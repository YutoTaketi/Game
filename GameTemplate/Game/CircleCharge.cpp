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
	m_spriteRender->Init(L"sprite/waku.dds",300, 200);
	m_position = { 350.0, -180.0, 0.0 };
	m_spriteRender->SetPosition(m_position);

	return true;
}

void CircleCharge::Update()
{

}
