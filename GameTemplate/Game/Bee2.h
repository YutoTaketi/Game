#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
class Player;
class Game;

class Bee2 : public IGameObject
{
public:
	Bee2();
	~Bee2();
	bool Start();
	void Move();
	void Turn();
	void BeeAtack();
	void Deth();
	void Update();

	int m_timer = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Player* m_player = nullptr;
	Game* game = nullptr;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;


};

