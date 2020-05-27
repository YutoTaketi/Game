#pragma once
class Boss;
class Game;
//�{�X�̕��˃G�t�F�N�g
class BossAfterBurn : public IGameObject
{
public:
	BossAfterBurn();
	~BossAfterBurn();
	bool Start();
	void Move(); //�ړ��֐�
	
	void Update(); //�X�V�֐�

	prefab::CEffect* effect = nullptr; //�G�t�F�N�g
	
	CVector3 m_position = CVector3::Zero; //���W
	CVector3 m_scale = CVector3::One; //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity; //��]

	Boss* boss = nullptr; //�{�X�̃|�C���^
	Game* game = nullptr; //Game�̃|�C���^
};

