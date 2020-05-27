#include "stdafx.h"
#include "Kabuto2.h"
#include "Player.h"
#include "Game2.h"
#include "Tama.h"
#include "KabutoBallet.h"

Kabuto2::Kabuto2()
{
}


Kabuto2::~Kabuto2()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("KabutoBallet");
}

bool Kabuto2::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Kabuto2.cmo");
	return true;
}

void Kabuto2::Move()
{
	//プレイヤーに向かって移動
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		playerLen = m_player->m_position - m_position;
		if (playerLen.Length() >= 400) {
			CVector3 playerKabuto = m_player->m_position - m_position;
			playerKabuto.Normalize();
			playerKabuto *= 2.5f;
			m_position += playerKabuto;

		}
		else {
			moveTimer++;
			if (moveTimer <= 80 && moveState == 0) {
				m_position.x++;
			}
			else if (moveTimer > 80 && moveState == 0) {
				moveState = 1;
				moveTimer = 0;
			}
			if (moveTimer <= 80 && moveState == 1)
			{
				m_position.x--;
			}
			else if (moveTimer > 80 && moveState == 1) {
				moveState = 0;
				moveTimer = 0;
			}
		}

		m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 400) {
			m_position = oldPos;
			m_position.y = 400;
		}
	}
}

void Kabuto2::Turn()
{
	//プレイヤーに向かって回転
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}

	CVector3 playerKabuto2 = m_player->m_position - m_position;
	float angle = atan2(playerKabuto2.x, playerKabuto2.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Kabuto2::Attack()
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
		
		if (m_player->m_position.y < m_position.y)
		{
		 kabutoBallet->m_moveSpeed.y -= 3.0;
		}
		

		AttackTimer = 0;
	}

}

void Kabuto2::Deth()
{
	if (game2 == nullptr) {
		game2 = FindGO<Game2>("Game2");
	}
	else {
		prefab::CSoundSource* ss;

		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaKabuto2 = tama->m_position - m_position;
			if (tamaKabuto2.Length() < 50.0f)
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

void Kabuto2::Update()
{
	m_player = FindGO<Player>("Player");
	CVector3 PlayertonoKyori = m_player->m_position - m_position;
	if (PlayertonoKyori.Length() < 1500) {
		Move();
		Turn();
		Attack();
		Deth();
	}
	
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}


