#include "stdafx.h"
#include "CircleCharge.h"
#include "Player.h"
#include "Capsule.h"


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
	CircleWaku->Init(L"sprite/MpBar.dds",424, 150);
	const CVector3 m_position = { 378.0, -240.0, 0.0 };
	CircleWaku->SetPosition(m_position);

	CircleGage = NewGO<prefab::CSpriteRender>(0);
	CircleGage->Init(L"sprite/circlegage.dds", w, 48);
	GagePos = { 230.0, -250.0, 0.0 };
	CircleGage->SetPosition(GagePos);
	CircleGage->SetPivot({ 0.0, 0.5 });
	return true;
}

void CircleCharge::GageGensyou()
{
	//サークルを出すとゲージが減少する。
	Player* player = FindGO<Player>("Player");
	if (player->CircleSummon() == true)
	{
		w = w - 52;
		CircleGage->Init(L"sprite/circlegage.dds", w, 48);
	}

}

void CircleCharge::GageCharge()
{
	//ゲージを回復
	if (w <= 290 && capsuleget == 1)
	{
		w = 290;
		CircleGage->Init(L"sprite/circlegage.dds", w, 48);
		capsuleget = 0;
	}
}

void CircleCharge::Update()
{
	GageGensyou();
	GageCharge();
}
