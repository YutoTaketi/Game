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
	CPhysicsStaticObject m_phyStaticObject; //静的物理オブジェクト
	CVector3 m_position = CVector3::Zero;
};

