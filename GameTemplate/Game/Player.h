#pragma once
#include "tkEngine/character/tkCharacterController.h"
//#include "tkEngine/graphics/effect/tkEffect.h"

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
	void Move();                //移動処理
	void Turn();                //回転処理
	void AnimationController(); //アニメーション
	bool CircleSummon();        //サークルを出す処理
	void Attack();              //攻撃処理
	void Deth();                //死んだときの処理
	void Update();              //更新処理

	//メンバ変数
	//プレイヤーロボのアニメーション
	enum EnAnimationClip {
		enAnimationClip_Player_Idle,
		enAnimationClip_Player_Shot,
		enAnimationClip_Player_Jump,
		enAnimationClip_Player_Run,
		//enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};


	int m_timer = 0;
	int attacktimer = 0;  //攻撃用のタイマー
	int WalkTimer = 0;    //移動サウンド用のタイマー
	//int HitHantei = 0;
	CAnimationClip m_animationClip[enAnimationClip_num];	//アニメーションクリップ。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;	//座標。
	CQuaternion m_rotation = CQuaternion::Identity;	//回転。
	CCharacterController m_charaCon;		//キャラクターコントローラー。
	CVector3 m_moveSpeed = CVector3::Zero;	//移動速度。
	//CVector3 BalletPlayer = CVector3::Zero;
	DemoCircle* m_demoCircle = nullptr;   //サークル
	Tama* m_tama = nullptr;               //攻撃の玉
	CircleCharge* m_circleCharge = nullptr; //サークルチャージ
	CShaderResourceView m_normalMap;      //プレイヤーロボのノーマルマップ
	CShaderResourceView m_specularMap;    //プレイヤーロボのスペキュラマップ


};

