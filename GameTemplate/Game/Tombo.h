#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class TomboAttackState;
class Tama;
class Game2;
class TomboJr;

class Tombo : public IGameObject
{
public:
	Tombo();
	~Tombo();
	bool Start();
	void Move();    //移動関数
	void Turn();    //回転関数
	void Attack();  //攻撃関数
	void Bunsin();  //分身関数
	void Hidan();   //被弾関数
	void Deth();    //死亡関数
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデル
	CVector3 m_position = CVector3::Zero;                  //座標
	CVector3 m_scale = CVector3::One;                      //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;        //回転
	Player* m_player = nullptr;                            //プレイヤーのポインタ
	CVector3 playerLen = CVector3::Zero;                   //プレイヤーとの距離

	TomboAttackState* tomboAttackState = nullptr;          //トンボの攻撃ステート
	Game2* game2 = nullptr;                                //gameのポインタ
	TomboJr* tomboJr[1] = { nullptr };                     //分身のポインタ

	int AttackTimer = 0;                                   //攻撃タイマー
	int Life = 500;                                        //ライフ
	int AttackChangeCount = 0;                             //攻撃が切り替わるまでのカウント
	int bunsinHantei = 0;  //分身の判定
	int bunsinStartTimer = 0;  //分身開始タイマー
};

