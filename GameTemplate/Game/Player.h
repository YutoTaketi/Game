#pragma once
#include "tkEngine/character/tkCharacterController.h"

class DemoCircle;
class Tama;
class CircleCharge;
class BeeBallet;
class PlayerHpBer;

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Move();
	void Turn();
	void AnimationController();
	bool CircleSummon();
	void Attack();
	void Deth();
	void Update();

	//メンバ変数
	enum EnAnimationClip {
		enAnimationClip_idle,
		enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};


	int m_timer = 0;
	int HitHantei = 0;
	CAnimationClip m_animationClip[enAnimationClip_num];	//アニメーションクリップ。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;	//座標。
	CQuaternion m_rotation = CQuaternion::Identity;	//回転。
	CCharacterController m_charaCon;		//キャラクターコントローラー。
	CVector3 m_moveSpeed = CVector3::Zero;	//移動速度。
	//CVector3 BalletPlayer = CVector3::Zero;
	DemoCircle* m_demoCircle = nullptr;
	Tama* m_tama = nullptr;
	CircleCharge* m_circleCharge = nullptr;
};

