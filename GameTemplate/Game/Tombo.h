#pragma once

class Player;
class TomboAttackState;
class Tama;
class Game2;

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
	void Hidan();
	void Deth();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Player* m_player = nullptr;
	CVector3 playerLen = CVector3::Zero;

	TomboAttackState* tomboAttackState = nullptr;
	Game2* game2 = nullptr;
	int AttackTimer = 0;
	int Life = 500;
};

