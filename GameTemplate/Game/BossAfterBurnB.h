#pragma once
class Game;
class Boss;
class BossAfterBurnB : public IGameObject
{
public:
	BossAfterBurnB();
	~BossAfterBurnB();
	bool Start();
	void Move();
	void Update();

	prefab::CEffect* effect = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Boss* boss = nullptr;
	Game* game = nullptr;
};

