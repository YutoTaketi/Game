#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Tama : public IGameObject
{
public:
	Tama();
	~Tama();
	bool Start();
	void Attack();
	void Update();

	Player* player = nullptr;
	int m_timer = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CVector3 m_scale = CVector3::Zero;
};

