#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class TomboAttackState : public IGameObject
{
public:
	TomboAttackState();
	~TomboAttackState();
	//攻撃ステートを返す
	static TomboAttackState& GetInstance()
	{
		static TomboAttackState attackNo;
		return attackNo;
	}
	//トンボの攻撃パターン
	enum AttackState {
		enState_Attack1,
		enState_Attack2,
		enState_Attack3
	};
	//攻撃番号をセットする。
	void SetAttackNumber(const AttackState& number)
	{
		m_AttackNo = number;
	}
	//攻撃番号を返す
	AttackState GetAttackNumber() const
	{
		return m_AttackNo;
	}
	AttackState m_AttackNo = enState_Attack1; //攻撃パターンの初期値
};

