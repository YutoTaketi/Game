#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class TomboAttackState : public IGameObject
{
public:
	TomboAttackState();
	~TomboAttackState();
	//�U���X�e�[�g��Ԃ�
	static TomboAttackState& GetInstance()
	{
		static TomboAttackState attackNo;
		return attackNo;
	}
	//�g���{�̍U���p�^�[��
	enum AttackState {
		enState_Attack1,
		enState_Attack2,
		enState_Attack3
	};
	//�U���ԍ����Z�b�g����B
	void SetAttackNumber(const AttackState& number)
	{
		m_AttackNo = number;
	}
	//�U���ԍ���Ԃ�
	AttackState GetAttackNumber() const
	{
		return m_AttackNo;
	}
	AttackState m_AttackNo = enState_Attack1; //�U���p�^�[���̏����l
};

