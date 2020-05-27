#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	bool Start();

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデル
	CPhysicsStaticObject m_phyStaticObject;                //静的物理オブジェクト
	CVector3 m_position = CVector3::Zero;                  //座標
	CVector3 m_scale = CVector3::One;                      //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;        //回転
};

