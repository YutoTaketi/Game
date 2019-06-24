#pragma once
class StageNumber;
class LoadGamen2 : public IGameObject
{
public:
	LoadGamen2();
	~LoadGamen2();
	bool Start();
	void Update();

	int LoadTimer = 0;
	prefab::CSpriteRender* m_spriteRender = nullptr;

	StageNumber* stagenumber = nullptr;
};

