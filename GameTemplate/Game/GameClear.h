#pragma once
class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();
	void Update();
	prefab::CSpriteRender* m_spriteRender = nullptr;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
	prefab::CSoundSource* clearSS;
};

