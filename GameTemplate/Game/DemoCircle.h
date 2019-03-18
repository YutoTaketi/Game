#pragma once
class Player;
class DemoCircle : public IGameObject
{
public:
	DemoCircle();
	~DemoCircle();
	bool Start();
	void Update();

	float m_timer = 0.0f;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position;
	CVector3 m_moveSpeed = CVector3::Zero;

	Player* m_player = nullptr;
};

