#pragma once
class Tittle : public IGameObject
{
public:
	Tittle();
	~Tittle();
	bool Start();
	void Update();

	prefab::CSpriteRender* m_spriteRender = nullptr;

};

