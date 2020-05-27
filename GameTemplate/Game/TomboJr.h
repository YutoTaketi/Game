#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Tombo;
class Game2;
class Tama;
class TomboAttackState;


class TomboJr : public IGameObject
{
public:
	TomboJr();
	~TomboJr();
	bool Start();
	void Move();   //移動関数
	void Turn();   //回転関数
	void Attack(); //攻撃関数
	void Deth();   //死亡関数
	void Update(); //更新関数

	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //スキンモデル
	CVector3 m_position = CVector3::Zero;                   //座標
	CVector3 m_scale = CVector3::One;                       //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;         //回転
	Player* m_player = nullptr;                             //プレイヤーのポインタ
	Tombo* tombo = nullptr;                                 //トンボのポインタ
	Game2* game2 = nullptr;                                 //ステージ２のポインタ
	CVector3 playerLen = CVector3::Zero;                    //プレイヤーとの距離
	TomboAttackState* tomboAttackState = nullptr;           //トンボの攻撃ステート

	int AttackChangeCount = 0;                              //攻撃変更カウント
	int AttackTimer = 0;                                    //攻撃タイマー
	int Life = 200;                                         //HP
	int KidouTimer = 180;                                   //動き出すまでのカウント
};

