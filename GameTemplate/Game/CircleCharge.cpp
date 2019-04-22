#include "stdafx.h"
#include "CircleCharge.h"
#include "Player.h"


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
	CircleWaku->Init(L"sprite/hpmp_bar.dds",300, 60);
	const CVector3 m_position = { 380.0, -250.0, 0.0 };
	CircleWaku->SetPosition(m_position);

	CircleGage = NewGO<prefab::CSpriteRender>(0);
	CircleGage->Init(L"sprite/circlegage.dds", 284, 34);
	GagePos = { 380.0, -250.0, 0.0 };
	CircleGage->SetPosition(GagePos);
	//CircleGage->Update(GagePos, { 0.0f, 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f }, {1.0f, 1.0f});
	return true;
}

void CircleCharge::GageGensyou()
{
	

}

void CircleCharge::Update()
{
	
}
