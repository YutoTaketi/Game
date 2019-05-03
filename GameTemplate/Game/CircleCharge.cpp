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
	CircleWaku->Init(L"sprite/hpmp_bar.dds",300, 60);
	const CVector3 m_position = { 380.0, -250.0, 0.0 };
	CircleWaku->SetPosition(m_position);

	CircleGage = NewGO<prefab::CSpriteRender>(0);
	CircleGage->Init(L"sprite/circlegage.dds", w, 34);
	GagePos = { 236.0, -250.0, 0.0 };
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
		w = w - 50;
		CircleGage->Init(L"sprite/circlegage.dds", w, 34);
	}

}

void CircleCharge::GageCharge()
{
	//カプセルを取るとゲージが復活
	/*Capsule* capsule = nullptr;
	if (capsule == nullptr) {
		capsule = FindGO<Capsule>("Capsule");
	}*/
	if (w <= 286 && capsuleget == 1)
	{
		w = 286;
		CircleGage->Init(L"sprite/circlegage.dds", w, 34);

	}
}

void CircleCharge::Update()
{
	GageGensyou();
	GageCharge();
}
