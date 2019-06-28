#pragma once
class TomboAttack1 : public IGameObject
{
public:
	TomboAttack1();
	~TomboAttack1();

	bool Start();
	void Update();
	int m_timer = 0;
	
	prefab::CEffect* effect = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;

	prefab::CEffect* effect2 = nullptr;
	CVector3 m_position2 = CVector3::Zero;
	CVector3 m_scale2 = CVector3::One;
	CVector3 m_moveSpeed2 = CVector3::Zero;
	CQuaternion m_rotation2 = CQuaternion::Identity;
};

