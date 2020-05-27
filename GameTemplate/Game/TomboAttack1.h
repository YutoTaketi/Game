#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class TomboAttack1 : public IGameObject
{
public:
	TomboAttack1();
	~TomboAttack1();

	bool Start();
	void Update(); //更新関数
	int m_timer = 0; //ビーム消滅までのタイマー
	
	prefab::CEffect* effect = nullptr;              //エフェクト ビーム
	CVector3 m_position = CVector3::Zero;           //座標
	CVector3 m_scale = CVector3::One;               //拡大率
	CVector3 m_moveSpeed = CVector3::Zero;          //移動速度
	CQuaternion m_rotation = CQuaternion::Identity; //回転

	prefab::CEffect* effect2 = nullptr;             //エフェクト2　ビーム発射口
	CVector3 m_position2 = CVector3::Zero;          //座標
	CVector3 m_scale2 = CVector3::One;              //拡大率
	CVector3 m_moveSpeed2 = CVector3::Zero;         //移動速度
	CQuaternion m_rotation2 = CQuaternion::Identity;//回転
};

