#pragma once
class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();
	void Update();
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

