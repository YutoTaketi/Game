#include "stdafx.h"
#include "Tombo.h"
#include "Player.h"
#include "TomboAttackState.h"
#include "TomboAttack1.h"
#include "TomboAttack2.h"
#include "Tama.h"
#include "Game2.h"
#include "TomboJr.h"



Tombo::Tombo()
{
}


Tombo::~Tombo()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("Attack1");
	DeleteGOs("Attack2");
	DeleteGOs("tomboDamegeEF");
	DeleteGOs("TomboJr1");
}

bool Tombo::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Tombo.cmo");
	m_scale = { 3.5f, 3.5f, 3.5f };
	m_position.y = 800.0f;
	//スポーンエフェクトを再生
	prefab::CEffect* tomboSpornEF = NewGO<prefab::CEffect>(0);
	//エフェクトを再生。
	tomboSpornEF->Play(L"effect/TomboSporn.efk");
	CVector3 SpornEfPos = m_position;
	CVector3 SpornEfscale = { 7.0, 7.0, 7.0 };
	SpornEfPos.y += 800.0f;
	tomboSpornEF->SetPosition(SpornEfPos);
	tomboSpornEF->SetScale(SpornEfscale);
	//トンボの鳴き声を再生
	prefab::CSoundSource* tomboNakigoeSS;
	tomboNakigoeSS = NewGO<prefab::CSoundSource>(0);
	tomboNakigoeSS->Init(L"sound/TomboNakigoe.wav");
	tomboNakigoeSS->SetVolume(2.0);
	tomboNakigoeSS->Play(false);
	return true;

}

void Tombo::Move()
{
	//プレイヤーに向かって移動
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		playerLen = m_player->m_position - m_position;
		if (playerLen.Length() >= 50) {
			CVector3 playerKabuto = m_player->m_position - m_position;
			playerKabuto.Normalize();
			playerKabuto *= 1.5f;
			m_position += playerKabuto;

		}


		m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 600) {
			m_position = oldPos;
			m_position.y = 600;
		}
	}
}

void Tombo::Turn()
{
	//プレイヤーに向かって回転
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}

	CVector3 playerBEE = m_player->m_position - m_position;
	float angle = atan2(playerBEE.x, playerBEE.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Tombo::Attack()
{
	//攻撃ステートをセット
	tomboAttackState = &TomboAttackState::GetInstance();
	//単発ビームを発射
	if (tomboAttackState->GetAttackNumber() == TomboAttackState::enState_Attack1)
	{
		AttackTimer++;
			if (AttackTimer == 70) {
				TomboAttack1* attack1 = NewGO<TomboAttack1>(0, "Attack1");
				attack1->m_position = m_position;
				attack1->m_position2 = m_position;
				attack1->m_position.y += 25.0;
				attack1->m_position.y += 60.0;
				attack1->m_rotation = m_rotation;
				attack1->m_rotation2 = m_rotation;
				CVector3 Tombomae = { 0, 0, 1 };
				m_rotation.Apply(Tombomae);
				attack1->m_moveSpeed = Tombomae * 25.0;
				//attack1->m_moveSpeed.y -= 2.0;
				if (m_player->m_position.y > m_position.y)
				{
				attack1->m_moveSpeed.y += 3.0;
				}
				else {
				attack1->m_moveSpeed.y -= 2.0;
				}

				AttackTimer = 0;
				AttackChangeCount += 1;
			}
		
		if (AttackChangeCount == 15) {
			tomboAttackState->SetAttackNumber(TomboAttackState::enState_Attack2);
		}
	}
	//極太ビームを発射
	if (tomboAttackState->GetAttackNumber() == TomboAttackState::enState_Attack2)
	{
	  TomboAttack2* attack2 = NewGO<TomboAttack2>(0, "Attack2");
			attack2->m_position = m_position;
			attack2->m_position.y += 25.0;
			attack2->m_rotation = m_rotation;
			CVector3 Tombomae = { 0, 0, 1 };
			m_rotation.Apply(Tombomae);
			attack2->m_moveSpeed = Tombomae * 1.0; 
			AttackChangeCount = 0;
			tomboAttackState->SetAttackNumber(TomboAttackState::enState_Attack1);
	}
}

//一定時間経過後
//分身する
void Tombo::Bunsin()
{
	bunsinStartTimer++;
	if (Life <= 300 && bunsinHantei== 0)
	{
		
		tomboJr[0] = NewGO<TomboJr>(0, "TomboJr1");
		tomboJr[0]->m_position = m_position;
		
		
		bunsinHantei = 1;
	}
		
}

void Tombo::Hidan()
{
	//プレイヤーの攻撃を受けた時の処理
	if (game2 == nullptr) {
		game2 = FindGO<Game2>("Game2");
	}
	else {
		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaTombo = tama->m_position - m_position;
			if (tamaTombo.Length() < 50.0f)
			{
				//ライフ減少
				Life -= 10;
				prefab::CEffect* damegeEF = NewGO<prefab::CEffect>(0, "tomboDamegeEF");
				//エフェクトを再生
				damegeEF->Play(L"effect/TomboDamege.efk");
				CVector3 emitPos = m_position;
				CVector3 emitScale = {9.5f, 9.5f, 9.5f };
				damegeEF->SetPosition(emitPos);
				damegeEF->SetScale(emitScale);
				prefab::CSoundSource* TomboDamageSS;
				TomboDamageSS = NewGO<prefab::CSoundSource>(0);
				TomboDamageSS->Init(L"sound/TomboDamage2.wav");
				TomboDamageSS->SetVolume(2.0);
				TomboDamageSS->Play(false);
				return false;
			}

			return true;
		});

	}
}

void Tombo::Deth()
{
	//ライフが0になると死亡
	if (game2 == nullptr)
	{
		game2 = FindGO<Game2>("Game2");
	}
	if (Life == 0) {
		game2->clearHantei = 1;
		prefab::CSoundSource* TomboDethSS;
		TomboDethSS = NewGO<prefab::CSoundSource>(0);
		TomboDethSS->Init(L"sound/TomboBakuhatu.wav");
		TomboDethSS->SetVolume(2.0);
		TomboDethSS->Play(false);

		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
		//エフェクトを再生
		effect->Play(L"effect/TomboDeth.efk");
		CVector3 emitPos = m_position;
		CVector3 emitScale = { 8.0f, 8.0f, 8.0f };
		effect->SetPosition(emitPos);
		effect->SetScale(emitScale);
		
		DeleteGO(this);
	}
	
}

void Tombo::Update()
{
	Move();
	Turn();
	Attack();
	Hidan();
	Bunsin();
	Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
