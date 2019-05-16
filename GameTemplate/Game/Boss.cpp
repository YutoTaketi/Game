#include "stdafx.h"
#include "Boss.h"
#include "Player.h"
#include "Tama.h"
#include "Game.h"


Boss::Boss()
{
}


Boss::~Boss()
{
	DeleteGO(m_skinModelRender);
}

bool Boss::Start()
{
	//アニメーションクリップのロード
	
	m_animationClip[enAnimationClip_Atack].Load(L"animData/Boss/Atack.tka");
	m_animationClip[enAnimationClip_Boost].Load(L"animData/Boss/Boost.tka");
	//アニメーションフラグ設定
	m_animationClip[enAnimationClip_Atack].SetLoopFlag(false);
	m_animationClip[enAnimationClip_Boost].SetLoopFlag(false);

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Boss.cmo", m_animationClip, enAnimationClip_num, enFbxUpAxisZ);
	m_position.y = 800.0;
	m_scale = { 2.0, 2.0, 2.0 };
	return true;
}
//移動（バーンエフェクトを再生）
void Boss::Move()
{ 
	
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		CVector3 playerBoss = m_player->m_position - m_position;
		playerBoss.Normalize();
		playerBoss *= 3.0f;
		m_position += playerBoss;

		//m_skinModelRender->SetPosition(m_position);
		CVector3 oldPos = m_position;
		if (m_position.y <= 100) {
			m_position = oldPos;
			m_position.y = 300;
		}
	}


}
//ターン
void Boss::Turn()
{
	
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}
	else {
		CVector3 playerBEE = m_player->m_position - m_position;
		float angle = atan2(playerBEE.x, playerBEE.z);
		m_rotation.SetRotation(CVector3::AxisY, angle);
	}
}
//攻撃
void Boss::Atack()
{
	//攻撃のリキャストタイム
	//m_skinModelRender->PlayAnimation(enAnimationClip_Atack, 0.0f);
}

//特定条件でターボ（タイマー制御にするかは未定 バーンエフェクト（青））
//プレイヤーとの距離が一定以上離れたら
void Boss::Boost()
{
}
//被弾判定
void Boss::Hidan()
{
	Game* game = nullptr;
	if (game == nullptr) {
		game = FindGO<Game>("Game");
		
		QueryGOs<Tama>("Tama", [&](Tama* tama)->bool {
			CVector3 tamaBee = tama->m_position - m_position;
			if (tamaBee.Length() < 50.0f)
			{
				//ライフ減少
				life -= 10;

				return false;
			}

			return true;
			});

	}
}
//ライフ0で消滅
void Boss::Deth()
{
	Game* game = nullptr;
	if (game == nullptr)
	{
		game = FindGO<Game>("Game");
		if (life == 0)
		{
			game->clearHantei = 1;
			DeleteGO(this);
		}
		
	}
	
}

void Boss::Update()
{
	//Move();
	//Turn();
	Hidan();
	Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
