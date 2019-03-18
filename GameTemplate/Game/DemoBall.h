#include "tkEngine/physics/tkPhysicsStaticObject.h"
#pragma once
class DemoBall : public IGameObject
{
public:
	DemoBall();
	~DemoBall();
	bool Start();
	
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CPhysicsStaticObject m_phyStaticObject; //静的物理オブジェクト
	CVector3 m_position = CVector3::Zero;

};

