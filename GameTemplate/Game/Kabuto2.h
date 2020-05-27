#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"



class Player;
class Tama;
class Game2;

class Kabuto2 : public IGameObject
{
public:
	Kabuto2();
	~Kabuto2();
	bool Start();
	void Move();   //移動速度
	void Turn();   //回転関数
	void Attack(); //攻撃関数
	void Deth();   //死亡関数
	void Update(); //更新関数

	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデル
	CVector3 m_position = CVector3::Zero;                  //座標
	CVector3 m_scale = CVector3::One;                      //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;        //回転
	Player* m_player = nullptr;                            //プレイヤーのポインタ
	CVector3 playerLen = CVector3::Zero;                   //プレイヤーとの距離
	Game2* game2 = nullptr;                                //game2のポインタ

	int AttackTimer = 0;                                   //攻撃する間隔タイマー
	int TossinHantei = 0;                                  //突進するかの判定
	int TossinStopTimer = 0;                               //突進が終わるまでのタイマー
	int moveTimer = 0;                                     //移動用タイマー
	int moveState = 0;                                     //ｘ軸方向移動のステート
};

