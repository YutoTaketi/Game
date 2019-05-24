#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class BossSlash;
class BossBall;
class BossAfterBurn;
class BossAfterBurnB;
class Game;
class Boss : public IGameObject
{
public:
	Boss();
	~Boss();

	bool Start();
	void Move();
	void Turn();
	void Attack();
	void Boost();
	void Hidan();
	void Deth();
	void Update();

	//アニメーションクリップ
	enum EnAnimationClip {
		enAnimationClip_Idle,
		enAnimationClip_Atack,
		enAnimationClip_Boost,
		enAnimationClip_num,
	};

	 
	CAnimationClip m_animationClip[enAnimationClip_num];
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;	//座標。
	CQuaternion m_rotation = CQuaternion::Identity;	//回転。
	CVector3 m_scale = CVector3::One;   //スケール
	prefab::CEffect* effect = nullptr;
	CVector3 emitPos = CVector3::Zero;    //エフェクトの座標
	CQuaternion emitRot = CQuaternion::Identity;  //エフェクトの回転
	CVector3 emitScale = CVector3::One;   //エフェクトのスケール
	 int life = 600; //ボスのライフ
	 int AttackTime = 0;
	 int boostHantei = 0; //
	 int MoveTimer = 0;  //スポーンしてから数秒後に動く
	Player* m_player = nullptr;
	Game* game = nullptr;
	BossAfterBurn* BurnEf = nullptr;  //赤いアフターバーナー
	BossAfterBurnB* BurnEfB = nullptr; //青いアフターバーナー
	BossBall* bossBall[4] = { nullptr }; //ボール攻撃
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM用のサウンドソース。
	prefab::CSoundSource* BossNakigoeSS;

};

