#pragma once
class Bee;
//Bee,Bee2�p�̍U��
class BeeBallet : public IGameObject
{
public:
	BeeBallet();
	~BeeBallet();

	bool Start();
	void Attack(); //�U���֐�
	void Update(); //�X�V�֐�

	int m_timer = 0;  //�e��������܂ł̃^�C�}�[
	Bee* bee; //�n�`�̃|�C���^
	prefab::CEffect* effect = nullptr;  //�U���G�t�F�N�g
	CVector3 m_position = CVector3::Zero; //���W
	CVector3 m_scale = CVector3::One;     //�g�嗦
	CVector3 m_moveSpeed = CVector3::Zero; //�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity; //��]

	
};

