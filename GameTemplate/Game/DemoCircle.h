#pragma once
class Player;
class DemoCircle : public IGameObject
{
public:
	DemoCircle();
	~DemoCircle();
	bool Start();
	void Update();       //更新関数

	float m_timer = 0.0f;                                   //サークル消滅タイマー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //スキンモデル
	CVector3 m_position = CVector3::Zero;                   //座標
	CVector3 m_moveSpeed = CVector3::Zero;                   //移動速度

	Player* m_player = nullptr;                             //プレイヤーのポインタ
};

