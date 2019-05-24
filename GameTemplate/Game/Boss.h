#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class BossSlash;
class BossBall;
class BossAfterBurn;
class BossAfterBurnB;
class Game;
class Boss : public IGameObject
{
public:
	Boss();
	~Boss();

	bool Start();
	void Move();
	void Turn();
	void Attack();
	void Boost();
	void Hidan();
	void Deth();
	void Update();

	//�A�j���[�V�����N���b�v
	enum EnAnimationClip {
		enAnimationClip_Idle,
		enAnimationClip_Atack,
		enAnimationClip_Boost,
		enAnimationClip_num,
	};

	 
	CAnimationClip m_animationClip[enAnimationClip_num];
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;	//���W�B
	CQuaternion m_rotation = CQuaternion::Identity;	//��]�B
	CVector3 m_scale = CVector3::One;   //�X�P�[��
	prefab::CEffect* effect = nullptr;
	CVector3 emitPos = CVector3::Zero;    //�G�t�F�N�g�̍��W
	CQuaternion emitRot = CQuaternion::Identity;  //�G�t�F�N�g�̉�]
	CVector3 emitScale = CVector3::One;   //�G�t�F�N�g�̃X�P�[��
	 int life = 600; //�{�X�̃��C�t
	 int AttackTime = 0;
	 int boostHantei = 0; //
	 int MoveTimer = 0;  //�X�|�[�����Ă��琔�b��ɓ���
	Player* m_player = nullptr;
	Game* game = nullptr;
	BossAfterBurn* BurnEf = nullptr;  //�Ԃ��A�t�^�[�o�[�i�[
	BossAfterBurnB* BurnEfB = nullptr; //���A�t�^�[�o�[�i�[
	BossBall* bossBall[4] = { nullptr }; //�{�[���U��
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM�p�̃T�E���h�\�[�X�B
	prefab::CSoundSource* BossNakigoeSS;

};

