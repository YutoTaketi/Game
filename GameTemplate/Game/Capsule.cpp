#include "stdafx.h"
#include "Capsule.h"
#include "Player.h"
#include "Game.h"
#include "Game2.h"
#include "CircleCharge.h"
#include "PlayerHpBer.h"
#include "StageNumber.h"


Capsule::Capsule()
{
}


Capsule::~Capsule()
{
	DeleteGO(m_skinModelRender);
}

bool Capsule::Start()
{
	stagenumber = &StageNumber::GetInstance();
	switch (stagenumber->GetStageNumber())
	{
	 case StageNumber::enState_Stage1:
		//ステージ1の時
		m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
		m_skinModelRender->Init(L"modelData/Capsule.cmo");
		break;
		//ステージ２の時
	 case StageNumber::enState_Stage2:
		 m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
		 m_skinModelRender->Init(L"modelData/Capsule2.cmo");
		 break;
	}
	
	
	return true;
}

void Capsule::CapsuleGet()
{
	stagenumber = &StageNumber::GetInstance();
	//ステージ1の時
	if (stagenumber->GetStageNumber() == StageNumber::enState_Stage1) {
		Game* game = nullptr;
		if (game == nullptr)
		{
			game = FindGO<Game>("Game");
			m_player = FindGO<Player>("Player");
			m_charge = FindGO<CircleCharge>("CircleCharge");
			
			if (m_player == nullptr)
			{
				//m_player = FindGO<Player>("Player");
				//m_charge = FindGO<CircleCharge>("CircleCharge");
			}
			else
			{
				get = m_player->m_position - m_position;
				get.Length();
				if (get.Length() < 80.0f) {
					prefab::CSoundSource* CapsulegetSS;
					CapsulegetSS = NewGO<prefab::CSoundSource>(0);
					CapsulegetSS->Init(L"sound/circleCharge.wav");
					CapsulegetSS->SetVolume(1.0);
					CapsulegetSS->Play(false);
					DeleteGO(this);
					m_charge->capsuleget = 1;
				}
			}
		}
	}

	//ステージ2の時
	if (stagenumber->GetStageNumber() == StageNumber::enState_Stage2) {
		Game2* game = nullptr;
		if (game == nullptr)
		{
			game = FindGO<Game2>("Game2");
			m_player = FindGO<Player>("Player");
			m_charge = FindGO<CircleCharge>("CircleCharge");
			
			if (m_player == nullptr)
			{
				//m_player = FindGO<Player>("Player");
				//m_charge = FindGO<CircleCharge>("CircleCharge");
			}
			else
			{
				//カプセルを取ったら音を鳴らす
				get = m_player->m_position - m_position;
				get.Length();
				if (get.Length() < 80.0f) {
					prefab::CSoundSource* CapsulegetSS;
					CapsulegetSS = NewGO<prefab::CSoundSource>(0);
					CapsulegetSS->Init(L"sound/circleCharge.wav");
					CapsulegetSS->SetVolume(1.0);
					CapsulegetSS->Play(false);
					DeleteGO(this);
					m_charge->capsuleget = 1;
				}
			}
		}
	}
	
}

void Capsule::Update()
{
	CapsuleGet();

	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
