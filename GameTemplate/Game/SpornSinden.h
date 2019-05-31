#pragma once
//#include "tkEngine/physics/tkPhysicsStaticObject.h"

class Game;
class Bee3;

class SpornSinden : public IGameObject
{
public:
	SpornSinden();
	~SpornSinden();

	bool Start();
	void BeeSporn();
	void BeeReSporn();
	void Update();

	int spornCount = 0;
	int SpornTimer = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Game* game = nullptr;
	Bee3* bee3 = nullptr;
	int i = 0;
	//CPhysicsStaticObject m_phyStaticObject = nullptr;	//静的物理オブジェクト
};

