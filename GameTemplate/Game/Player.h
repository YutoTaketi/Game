#pragma once
#include "tkEngine/character/tkCharacterController.h"

class DemoCircle;
class Tama;
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Move();
	void Turn();
	void AnimationController();
	void CircleSummon();
	void Attack();
	void Update();

	//メンバ変数
	enum EnAnimationClip {
		enAnimationClip_idle,
		enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};


	int m_timer = 0;
	const int SetiSeigen = 3;
	CAnimationClip m_animationClip[enAnimationClip_num];	//アニメーションクリップ。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;	//座標。
	CQuaternion m_rotation = CQuaternion::Identity;	//回転。
	CCharacterController m_charaCon;		//キャラクターコントローラー。
	CVector3 m_moveSpeed = CVector3::Zero;	//移動速度。

	DemoCircle* m_demoCircle = nullptr;
	Tama* m_tama = nullptr;
};

