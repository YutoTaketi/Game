#pragma once
class StageNumber;  //制作中のみ
class LoadGamen : public IGameObject
{
public:
	LoadGamen();
	~LoadGamen();
	bool Start();
	void Update();
	int LoadTimer = 0;
	prefab::CSpriteRender* m_spriteRender = nullptr;
	StageNumber* stagenumber = nullptr; //制作中のみ
};

