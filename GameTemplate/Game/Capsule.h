#pragma once
class Player;
class Game;
class CircleCharge;

class Capsule : public IGameObject
{
public:
	Capsule();
	~Capsule();
	bool Start();
	void CapsuleGet();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Player* m_player = nullptr;
	CircleCharge* m_charge = nullptr;
	CVector3 get = CVector3::Zero;
};

