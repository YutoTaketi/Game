#pragma once
class Boss;
class Game;
//ボスの噴射エフェクト
class BossAfterBurn : public IGameObject
{
public:
	BossAfterBurn();
	~BossAfterBurn();
	bool Start();
	void Move(); //移動関数
	
	void Update(); //更新関数

	prefab::CEffect* effect = nullptr; //エフェクト
	
	CVector3 m_position = CVector3::Zero; //座標
	CVector3 m_scale = CVector3::One; //拡大率
	CQuaternion m_rotation = CQuaternion::Identity; //回転

	Boss* boss = nullptr; //ボスのポインタ
	Game* game = nullptr; //Gameのポインタ
};

