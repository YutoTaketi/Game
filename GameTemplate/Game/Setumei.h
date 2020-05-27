#pragma once
class Setumei : public IGameObject
{
public:
	Setumei();
	~Setumei();
	bool Start();
	void Update();

	prefab::CSpriteRender* m_spriteRender = nullptr; //背景スプライト
	CVector3 m_position = CVector3::Zero;            //座標
	prefab::CSpriteRender* m_spriteRender2 = nullptr;//説明スプライト

	int SeniTimaer = 0;                               //遷移するまでのタイマー
};

