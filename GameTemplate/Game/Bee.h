#pragma once
class Player;


class Bee : public IGameObject
{
public:
	Bee();
	~Bee();

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
	Player* m_player;
};

