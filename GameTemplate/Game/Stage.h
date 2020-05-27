#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	bool Start();

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //�X�L�����f��
	CPhysicsStaticObject m_phyStaticObject;                //�ÓI�����I�u�W�F�N�g
	CVector3 m_position = CVector3::Zero;                  //���W
	CVector3 m_scale = CVector3::One;                      //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity;        //��]
};

