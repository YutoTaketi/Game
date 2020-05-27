#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"

class Player;
class Game;

class Bee2 : public IGameObject
{
public:
	Bee2();
	~Bee2();
	bool Start();
	void Move();      //�ړ�����
	void Turn();      //��]����
	void BeeAtack();  //�U������
	void Deth();      //���S����
	void Update();    //�X�V����

	int m_timer = 0;   //�U���p�^�C�}�[
	int moveTimer = 0; //�ړ��p�^�C�}�[
	int moveState = 0; //�ړ��p����
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //�X�L�����f��
	CVector3 m_position = CVector3::Zero;            //���W
	CVector3 m_scale = CVector3::One;                //�g�嗦
	//CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;  //��]
	Player* m_player = nullptr;                      //�v���C���[�̃|�C���^
	Game* game = nullptr;                            //Game�̃|�C���^
	prefab::CSoundSource* m_bgmSoundSource = nullptr; //�T�E���h
	CVector3 playerLen = CVector3::Zero;              //�v���C���[�Ƃ̋���
	

};

