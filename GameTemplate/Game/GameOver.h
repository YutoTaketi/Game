#pragma once
class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();

	bool Start();
	void Update();

	prefab::CSpriteRender* m_spriteRender = nullptr;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
	prefab::CSoundSource* overSS;
};

