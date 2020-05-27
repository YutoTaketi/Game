#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Tombo;
class Player;
class TomboAttack2 : public IGameObject
{
public:
	TomboAttack2();
	~TomboAttack2();
	bool Start();
	void Update(); //�X�V�֐�

	int m_timer = 0;  //�U���p�^�C�}�[

	prefab::CEffect* effect = nullptr;               //�G�t�F�N�g
	CVector3 m_position = CVector3::Zero;            //���W
	CVector3 m_scale = CVector3::One;                //�g�嗦
	CVector3 m_moveSpeed = CVector3::Zero;           //�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity;  //��]
};

