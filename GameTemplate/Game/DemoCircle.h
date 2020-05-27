#pragma once
class Player;
class DemoCircle : public IGameObject
{
public:
	DemoCircle();
	~DemoCircle();
	bool Start();
	void Update();       //�X�V�֐�

	float m_timer = 0.0f;                                   //�T�[�N�����Ń^�C�}�[
	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                   //���W
	CVector3 m_moveSpeed = CVector3::Zero;                   //�ړ����x

	Player* m_player = nullptr;                             //�v���C���[�̃|�C���^
};

