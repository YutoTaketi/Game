#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"

class Player;
class Game;

class Bee : public IGameObject
{
public:
	Bee();
	~Bee();

	bool Start();
	void Move();      //�ړ��֐�
	void Turn();      //��]�֐�
	void BeeAtack();  //�U���֐�
	void Deth();      //���S�֐�
	void Update();    //�X�V�֐�

	

public:
	
	int m_timer = 0; //�U���p�̃^�C�}�[
	
	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //�X�L�����f��
	CVector3 m_position = CVector3::Zero;  //���W
	CVector3 m_scale = CVector3::One;      //�g��

	CQuaternion m_rotation = CQuaternion::Identity; //��]
	Player* m_player = nullptr; //�v���C���[�̃|�C���^
	Game* game = nullptr;  //Game�̃|�C���^
	prefab::CSoundSource* m_bgmSoundSource = nullptr;  //�T�E���h
	CVector3 playerLen = CVector3::Zero;     //�v���C���[�Ƃ̋���

	

};

