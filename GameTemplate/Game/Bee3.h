#pragma once
class Player;
class Game;
class Tama;
class Bee3 : public IGameObject
{
public:
	Bee3();
	~Bee3();
	bool Start();
	void Move();
	void Turn();
	void Deth();
	void Update();


	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;

	Player* m_player = nullptr;
	Game* game = nullptr;
};

