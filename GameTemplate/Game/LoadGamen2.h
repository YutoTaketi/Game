#pragma once
class StageNumber;
class LoadGamen2 : public IGameObject
{
public:
	LoadGamen2();
	~LoadGamen2();
	bool Start();
	void Update();  //更新関数

	int LoadTimer = 0;    //遷移するまでのタイマー
	prefab::CSpriteRender* m_spriteRender = nullptr; //スプライト

	StageNumber* stagenumber = nullptr; //ステージナンバー
};

