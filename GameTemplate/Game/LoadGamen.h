#pragma once
class LoadGamen : public IGameObject
{
public:
	LoadGamen();
	~LoadGamen();
	bool Start();
	void Update();
	int LoadTimer = 0;
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

