#pragma once
class Player;
class Tombo;
class Game2;
class Tama;

class TomboJr : public IGameObject
{
public:
	TomboJr();
	~TomboJr();
	bool Start();
	void Move();
	void Turn();
	void Attack();
	void Deth();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Player* m_player = nullptr;
	Tombo* tombo = nullptr;
	Game2* game2 = nullptr;
	CVector3 playerLen = CVector3::Zero;

	int AttackTimer = 0;
};

