#pragma once
class SpornSinden : public IGameObject
{
public:
	SpornSinden();
	~SpornSinden();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
};

