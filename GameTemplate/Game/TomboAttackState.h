#pragma once
class TomboAttackState : public IGameObject
{
public:
	TomboAttackState();
	~TomboAttackState();

	static TomboAttackState& GetInstance()
	{
		static TomboAttackState attackNo;
		return attackNo;
	}
	enum AttackState {
		enState_Attack1,
		enState_Attack2,
		enState_Attack3
	};
	void SetStage(const AttackState& number)
	{
		m_AttackNo = number;
	}
	AttackState GetAttackNumber() const
	{
		return m_AttackNo;
	}
	AttackState m_AttackNo = enState_Attack1;
};

