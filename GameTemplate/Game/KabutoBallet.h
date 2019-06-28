#pragma once
class KabutoBallet : public IGameObject
{
public:
	KabutoBallet();
	~KabutoBallet();
	bool Start();
	void Update();
	int m_timer = 0;

	prefab::CEffect* effect = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
};

