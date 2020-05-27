#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class TomboAttack1 : public IGameObject
{
public:
	TomboAttack1();
	~TomboAttack1();

	bool Start();
	void Update(); //�X�V�֐�
	int m_timer = 0; //�r�[�����ł܂ł̃^�C�}�[
	
	prefab::CEffect* effect = nullptr;              //�G�t�F�N�g �r�[��
	CVector3 m_position = CVector3::Zero;           //���W
	CVector3 m_scale = CVector3::One;               //�g�嗦
	CVector3 m_moveSpeed = CVector3::Zero;          //�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity; //��]

	prefab::CEffect* effect2 = nullptr;             //�G�t�F�N�g2�@�r�[�����ˌ�
	CVector3 m_position2 = CVector3::Zero;          //���W
	CVector3 m_scale2 = CVector3::One;              //�g�嗦
	CVector3 m_moveSpeed2 = CVector3::Zero;         //�ړ����x
	CQuaternion m_rotation2 = CQuaternion::Identity;//��]
};

