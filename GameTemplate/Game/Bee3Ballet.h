#pragma once
//ハチ３用の攻撃玉
class Bee3Ballet : public IGameObject
{
public:
	Bee3Ballet();
	~Bee3Ballet();
	bool Start();
	void Update(); //更新関数

	int m_timer = 0; //消滅するまでのタイマー

	prefab::CEffect* effect = nullptr;  //攻撃エフェクト
	CVector3 m_position = CVector3::Zero; //座標
	CVector3 m_scale = CVector3::One;     //拡大率
	CVector3 m_moveSpeed = CVector3::Zero; //移動速度
	CQuaternion m_rotation = CQuaternion::Identity; //回転
};

