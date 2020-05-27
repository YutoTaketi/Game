#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Game2;
class Tama;
class KabutoBallet;

class Kabuto : public IGameObject
{
public:
	Kabuto();
	~Kabuto();
	bool Start();
	void Move();    //移動関数
	void Turn();    //回転関数
	void Attack();  //攻撃関数
	void Deth();    //死亡関数
	void Update();  //更新関数

	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //スキンモデル
	CVector3 m_position = CVector3::Zero;                   //座標
	CVector3 m_scale = CVector3::One;                       //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;         //回転
	Player* m_player = nullptr;                             //プレイヤーのポインタ
	CVector3 playerLen = CVector3::Zero;                    //プレイヤーとの距離

	Game2* game2 = nullptr;                                 //game2のポインタ
	int AttackTimer = 0;                                    //攻撃の間隔タイマー
	int TossinHantei = 0;                                   //突進するかの判定
	int TossinStopTimer = 0;                                //突進終わるまでのタイマー
};

