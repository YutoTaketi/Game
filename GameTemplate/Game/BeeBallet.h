#pragma once
class Bee;
//Bee,Bee2用の攻撃
class BeeBallet : public IGameObject
{
public:
	BeeBallet();
	~BeeBallet();

	bool Start();
	void Attack(); //攻撃関数
	void Update(); //更新関数

	int m_timer = 0;  //弾が消えるまでのタイマー
	Bee* bee; //ハチのポインタ
	prefab::CEffect* effect = nullptr;  //攻撃エフェクト
	CVector3 m_position = CVector3::Zero; //座標
	CVector3 m_scale = CVector3::One;     //拡大率
	CVector3 m_moveSpeed = CVector3::Zero; //移動速度
	CQuaternion m_rotation = CQuaternion::Identity; //回転

	
};

