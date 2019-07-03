#pragma once

class Player;
class TomboAttackState;
class Tama;
class Game2;
class TomboJr;

class Tombo : public IGameObject
{
public:
	Tombo();
	~Tombo();
	bool Start();
	void Move();
	void Turn();
	void Attack();
	void Bunsin();
	void Hidan();
	void Deth();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Player* m_player = nullptr;
	CVector3 playerLen = CVector3::Zero;

	TomboAttackState* tomboAttackState = nullptr;
	Game2* game2 = nullptr;
	TomboJr* tomboJr[2] = { nullptr };
	Player* player = nullptr;
	int AttackTimer = 0;
	int Life = 500;
	int AttackChangeCount = 0;
	int bunsinHantei = 0;  //分身の判定
	int bunsinStartTimer = 0;  //分身開始タイマー
};

