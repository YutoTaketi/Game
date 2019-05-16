#pragma once
class Player;
class Boss : public IGameObject
{
public:
	Boss();
	~Boss();

	bool Start();
	void Move();
	void Turn();
	void Atack();
	void Boost();
	void Hidan();
	void Deth();
	void Update();

	//�A�j���[�V�����N���b�v
	enum EnAnimationClip {
		enAnimationClip_Atack,
		enAnimationClip_Boost,
		enAnimationClip_num,
	};

	 
	CAnimationClip m_animationClip[enAnimationClip_num];
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;	//���W�B
	CQuaternion m_rotation = CQuaternion::Identity;	//��]�B
	CVector3 m_scale = CVector3::One;   //�X�P�[��
	 int life = 200; //�{�X�̃��C�t
	Player* m_player = nullptr;


};

