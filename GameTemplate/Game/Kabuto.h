#pragma once

class Player;
class Game2;
class Tama;
class KabutoBallet;

class Kabuto : public IGameObject
{
public:
	Kabuto();
	~Kabuto();
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
	CVector3 playerLen = CVector3::Zero;

	Game2* game2 = nullptr;
	int AttackTimer = 0;
	int TossinHantei = 0;
};

