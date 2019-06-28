#pragma once

class Player;
class TomboAttackState;

class Tombo : public IGameObject
{
public:
	Tombo();
	~Tombo();
	bool Start();
	void Move();
	void Turn();
	void Attack();
	void Bunsin();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Player* m_player = nullptr;
	CVector3 playerLen = CVector3::Zero;

	TomboAttackState* tomboAttackState = nullptr;
	int AttackTimer = 0;
};

