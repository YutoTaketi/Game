#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	bool Start();

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CPhysicsStaticObject m_phyStaticObject; //�ÓI�����I�u�W�F�N�g
	CVector3 m_position = CVector3::Zero;
};

