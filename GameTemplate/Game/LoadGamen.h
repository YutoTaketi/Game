#pragma once

class LoadGamen : public IGameObject
{
public:
	LoadGamen();
	~LoadGamen();
	bool Start();
	void Update();       //更新関数
	int LoadTimer = 0;  //遷移するまでのタイマー
	prefab::CSpriteRender* m_spriteRender = nullptr; //スプライト
	
};

