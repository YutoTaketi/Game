#include "stdafx.h"
#include "Kabuto.h"
#include "Player.h"
#include "Game2.h"
#include "Tama.h"
#include "KabutoBallet.h"

Kabuto::Kabuto()
{
}


Kabuto::~Kabuto()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("KabutoBallet");
}

bool Kabuto::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Kabuto.cmo");
	return true;
}

void Kabuto::Move()
{
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	//プレイヤーに向かって移動
	else {
		playerLen = m_player->m_position - m_position;
		if (playerLen.Length() >= 50) {
			CVector3 playerKabuto = m_player->m_position - m_position;
			playerKabuto.Normalize();
			playerKabuto *= 2.5f;
			m_position += playerKabuto;

		}
		

		m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (TossinHantei == 0) {
			if (m_position.y <= 400) {
				m_position = oldPos;
				m_position.y = 400;
			}
		}
		
	}
}

void Kabuto::Turn()
{
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	//プレイヤーに向かって回転
	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Kabuto::Attack()
{
	//ビームを出す 
	AttackTimer++;
	
	CVector3 KabutoPlayer = m_player->m_position - m_position;
	if (KabutoPlayer.Length() < 500.0f)
	{
		TossinHantei = 1;
		//突進
		if (TossinHantei == 1) {
			prefab::CEffect* TossinEF = NewGO<prefab::CEffect>(0);
			TossinEF->Play(L"effect/KabutoTossin.efk");
			CVector3 TossinEFpos = m_position;
			TossinEFpos.y += 50.0;
			CVector3 TossinEFscale = { 6.0, 6.0, 6.0 };
			CQuaternion TossinEFrot = m_rotation;
			TossinEF->SetPosition(m_position);
			TossinEF->SetRotation(TossinEFrot);
			TossinHantei = 0;
		}
		KabutoPlayer.Normalize();
		KabutoPlayer *= 3.5;
		m_position += KabutoPlayer;
		CVector3 TossinAfter = m_position;
		if (KabutoPlayer.Length() <= 50.0)
		{
			TossinStopTimer++;
			if (TossinStopTimer < 180) {
				m_position = TossinAfter;

			}
			
		}
		TossinStopTimer = 0;
	}
	if (AttackTimer == 70 && KabutoPlayer.Length() >= 500.0) {
		
		KabutoBallet* kabutoBallet = NewGO<KabutoBallet>(0, "KabutoBallet");
		kabutoBallet->m_position = m_position;
		kabutoBallet->m_position.y += 25.0;
		kabutoBallet->m_rotation = m_rotation;

		CVector3 Kabutomae = { 0, 0, 1 };
		m_rotation.Apply(Kabutomae);
		kabutoBallet->m_moveSpeed = Kabutomae * 25.0;
		//slash->m_moveSpeed.y -= 2.0;
		if (m_player->m_position.y < m_position.y)
		{
		   kabutoBallet->m_moveSpeed.y -= 3.0;
		 
		   
		}
		
		AttackTimer = 0;
	}

}

void Kabuto::Deth()
{
	if (game2 == nullptr) {
		game2 = FindGO<Game2>("Game2");
	}
	else {
		prefab::CSoundSource* ss;

		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaBee = tama->m_position - m_position;
			if (tamaBee.Length() < 50.0f)
			{

				//エフェクトを作成
				prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
				//エフェクトを再生
				effect->Play(L"effect/KabutoDeth.efk");
				CVector3 emitPos = m_position;
				CVector3 emitScale = { 2.0, 2.0, 2.0 };
				effect->SetPosition(emitPos);
				effect->SetScale(emitScale);
				//爆発音を鳴らす
				ss = NewGO<prefab::CSoundSource>(0);
				ss->Init(L"sound/KabutoBakuhatu.wav");
				ss->SetVolume(2.0);
				ss->Play(false);
				game2->KabutoDethCount++;
				DeleteGO(this);
				return false;
			}

			return true;
		});


	}

}

void Kabuto::Update()
{
	Move();
	Turn();
	Attack();
	Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}