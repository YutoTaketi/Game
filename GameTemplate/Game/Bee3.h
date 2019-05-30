#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Game;
class Tama;

class Bee3 : public IGameObject
{
public:
	Bee3();
	~Bee3();
	bool Start();
	void Move();
	void Turn();
	void Attack();
	void Deth();
	void Update();

	int m_timer = 0;
	int StartUp = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
	prefab::CEffect* effect;
	Player* m_player = nullptr;
	Game* game = nullptr;
};

