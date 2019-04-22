#pragma once
class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();

	prefab::CSpriteRender* m_spriteRender = nullptr;
};

