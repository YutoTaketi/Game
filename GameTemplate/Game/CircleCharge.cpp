#include "stdafx.h"
#include "CircleCharge.h"


CircleCharge::CircleCharge()
{
}


CircleCharge::~CircleCharge()
{
	DeleteGO(CircleWaku);
	DeleteGO(CircleGage);
}

bool CircleCharge::Start()
{
	CircleWaku = NewGO<prefab::CSpriteRender>(0);
	CircleWaku->Init(L"sprite/hpmp_bar.dds",250, 80);
	const CVector3 m_position = { 380.0, -250.0, 0.0 };
	CircleWaku->SetPosition(m_position);

	CircleGage = NewGO<prefab::CSpriteRender>(0);
	CircleGage->Init(L"sprite/circlegage.dds", 235, 43);
	GagePos = { 380.0, -250.0, 0.0 };
	CircleGage->SetPosition(GagePos);
	return true;
}

void CircleCharge::Update()
{

}
