#include "stdafx.h"
#include "Player.h"
#include "DemoCircle.h"
#include "Tama.h"
#include "CircleCharge.h"
#include "BeeBallet.h"
#include "PlayerHpBer.h"
#include "Game.h"
#include "GameOver.h"

Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
}

bool Player::Start()
{
	//アニメーションクリップのロード
	m_animationClip[enAnimationClip_idle].Load(L"animData/unityChan/idle.tka");
	m_animationClip[enAnimationClip_run].Load(L"animData/unityChan/run.tka");
	m_animationClip[enAnimationClip_jump].Load(L"animData/unityChan/jump.tka");
	//ループフラグの設定
	m_animationClip[enAnimationClip_idle].SetLoopFlag(true);
	m_animationClip[enAnimationClip_run].SetLoopFlag(true);
	m_animationClip[enAnimationClip_jump].SetLoopFlag(false);

	m_charaCon.Init(
		20.0,
		50.0f,
		m_position
	);

	//スキンモデルレンダラーを作成
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo", m_animationClip, enAnimationClip_num, enFbxUpAxisY );
	return true;
}

void Player::Move()
{
	//左スティック入力量をうけとる
	float lStick_x = Pad(0).GetLStickXF();
	float lStick_y = Pad(0).GetLStickYF();
	//カメラの前方方向と右方向を取得
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ平面での前方方向、右方向に変換する。
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();
	//XZ成分の移動速度をクリア
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed += cameraForward * lStick_y * 200.0f;
	m_moveSpeed += cameraRight * lStick_x * 200.0f;

	//ジャンプ
	if (Pad(0).IsTrigger(enButtonA)
		&& m_charaCon.IsOnGround())
	{
		m_moveSpeed.y = 400.0f;
	}
	//キャラクターコントローラー
	m_position = m_charaCon.Execute(m_moveSpeed, GameTime().GetFrameDeltaTime());
}

void Player::Turn()
{
	if (fabsf(m_moveSpeed.x) < 0.001f
		&& fabsf(m_moveSpeed.z) < 0.001f) {
		return;
	}

	float angle = atan2(m_moveSpeed.x, m_moveSpeed.z);
	m_rotation.SetRotation(CVector3::AxisY, angle);
}

void Player::AnimationController()
{
	if (m_charaCon.IsJump() == false) {
		if (Pad(0).GetLStickXF() || Pad(0).GetLStickYF()) {
			m_skinModelRender->PlayAnimation(enAnimationClip_run, 0.0f);
		}
		else {
			m_skinModelRender->PlayAnimation(enAnimationClip_idle, 0.0f);

		}
	}
	if (Pad(0).IsTrigger(enButtonA)) {
		m_skinModelRender->PlayAnimation(enAnimationClip_jump, 0.0f);
	}
}

//もしR2トリガーが押されたら、サークルを出す。
bool Player::CircleSummon()
{
	CircleCharge* ciclecharge = FindGO<CircleCharge>("CircleCharge");
		//もし6つ設置したら、設置できない
	//もしR2トリガーが押されたら、サークルを出す。
	if ( ciclecharge->w > 0 && Pad(0).IsTrigger(enButtonB)) {

		m_demoCircle = NewGO<DemoCircle>(0, "DemoCircle");
		m_demoCircle->m_position.x = m_position.x + 5.0f;
		m_demoCircle->m_position.y = m_position.y + 40.0f;
		m_demoCircle->m_position.z = m_position.z + 5.0f;
		return true;
	}
	else
	{
		return false;
	}
	
	
}

void Player::Attack()
{
	

	if (Pad(0).IsTrigger(enButtonRB2)) {
		m_tama = NewGO<Tama>(0, "Tama");
		m_tama->m_position = m_position;
		
		m_tama->m_position.y += 70.0;
		
	}
}

void Player::Deth()
{
	/*PlayerHpBer* HpBer = FindGO<PlayerHpBer>("HpBer");
	Game* game = FindGO<Game>("Game");
	if (HpBer->w <= 0)
	{
		NewGO<GameOver>(0, "GameOver");
		//DeleteGO(game);
	}*/
}


void Player::Update()
{
	Move();
	Turn();
	AnimationController();
	CircleSummon();
	Attack();
	//Deth();
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}