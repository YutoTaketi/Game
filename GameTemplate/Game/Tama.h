#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Tama : public IGameObject
{
public:
	Tama();
	~Tama();
	bool Start();
	void Attack(); //攻撃関数
	void Update(); //更新関数

	Player* player = nullptr; //プレイヤーのポインタ
	int m_timer = 0;          //
	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //スキンモデル
	CVector3 m_position = CVector3::Zero;                   //座標
	CVector3 m_moveSpeed = CVector3::Zero;                  //移動速度
	CVector3 m_scale = CVector3::Zero;                      //拡大率
};

