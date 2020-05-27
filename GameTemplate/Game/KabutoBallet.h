#pragma once
class Player;
class Kabuto;
class Kabuto2;
class KabutoBallet : public IGameObject
{
public:
	KabutoBallet();
	~KabutoBallet();
	bool Start();
	void Update();   //更新関数
	int m_timer = 0; //消滅までのタイマー

	prefab::CEffect* effect = nullptr;                //エフェクト
	CVector3 m_position = CVector3::Zero;             //座標
	CVector3 m_scale = CVector3::One;                 //拡大率
	CVector3 m_moveSpeed = CVector3::Zero;            //移動速度
	CQuaternion m_rotation = CQuaternion::Identity;   //回転

};

