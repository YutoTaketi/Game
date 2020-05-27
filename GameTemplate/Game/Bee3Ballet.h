#pragma once
//�n�`�R�p�̍U����
class Bee3Ballet : public IGameObject
{
public:
	Bee3Ballet();
	~Bee3Ballet();
	bool Start();
	void Update(); //�X�V�֐�

	int m_timer = 0; //���ł���܂ł̃^�C�}�[

	prefab::CEffect* effect = nullptr;  //�U���G�t�F�N�g
	CVector3 m_position = CVector3::Zero; //���W
	CVector3 m_scale = CVector3::One;     //�g�嗦
	CVector3 m_moveSpeed = CVector3::Zero; //�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity; //��]
};

