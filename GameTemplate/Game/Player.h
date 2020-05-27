#pragma once
#include "tkEngine/character/tkCharacterController.h"
//#include "tkEngine/graphics/effect/tkEffect.h"

class DemoCircle;
class Tama;
class CircleCharge;
class BeeBallet;
class PlayerHpBer;

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Move();                //�ړ�����
	void Turn();                //��]����
	void AnimationController(); //�A�j���[�V����
	bool CircleSummon();        //�T�[�N�����o������
	void Attack();              //�U������
	void Deth();                //���񂾂Ƃ��̏���
	void Update();              //�X�V����

	//�����o�ϐ�
	//�v���C���[���{�̃A�j���[�V����
	enum EnAnimationClip {
		enAnimationClip_Player_Idle,
		enAnimationClip_Player_Shot,
		enAnimationClip_Player_Jump,
		enAnimationClip_Player_Run,
		//enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};


	int m_timer = 0;
	int attacktimer = 0;  //�U���p�̃^�C�}�[
	int WalkTimer = 0;    //�ړ��T�E���h�p�̃^�C�}�[
	//int HitHantei = 0;
	CAnimationClip m_animationClip[enAnimationClip_num];	//�A�j���[�V�����N���b�v�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;	//���W�B
	CQuaternion m_rotation = CQuaternion::Identity;	//��]�B
	CCharacterController m_charaCon;		//�L�����N�^�[�R���g���[���[�B
	CVector3 m_moveSpeed = CVector3::Zero;	//�ړ����x�B
	//CVector3 BalletPlayer = CVector3::Zero;
	DemoCircle* m_demoCircle = nullptr;   //�T�[�N��
	Tama* m_tama = nullptr;               //�U���̋�
	CircleCharge* m_circleCharge = nullptr; //�T�[�N���`���[�W
	CShaderResourceView m_normalMap;      //�v���C���[���{�̃m�[�}���}�b�v
	CShaderResourceView m_specularMap;    //�v���C���[���{�̃X�y�L�����}�b�v


};

