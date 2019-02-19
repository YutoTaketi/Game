#pragma once
class Player;
class DemoCircle : public IGameObject
{
public:
	DemoCircle();
	~DemoCircle();
	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;

	Player* m_player = nullptr;
};

