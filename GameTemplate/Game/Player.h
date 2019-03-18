#pragma once
#include "tkEngine/character/tkCharacterController.h"

class DemoCircle;
class Tama;
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Move();
	void Turn();
	void AnimationController();
	void CircleSummon();
	void Attack();
	void Update();

	//�����o�ϐ�
	enum EnAnimationClip {
		enAnimationClip_idle,
		enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};


	int m_timer = 0;
	const int SetiSeigen = 3;
	CAnimationClip m_animationClip[enAnimationClip_num];	//�A�j���[�V�����N���b�v�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;	//���W�B
	CQuaternion m_rotation = CQuaternion::Identity;	//��]�B
	CCharacterController m_charaCon;		//�L�����N�^�[�R���g���[���[�B
	CVector3 m_moveSpeed = CVector3::Zero;	//�ړ����x�B

	DemoCircle* m_demoCircle = nullptr;
	Tama* m_tama = nullptr;
};

