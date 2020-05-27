#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Tombo;
class Game2;
class Tama;
class TomboAttackState;


class TomboJr : public IGameObject
{
public:
	TomboJr();
	~TomboJr();
	bool Start();
	void Move();   //�ړ��֐�
	void Turn();   //��]�֐�
	void Attack(); //�U���֐�
	void Deth();   //���S�֐�
	void Update(); //�X�V�֐�

	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                   //���W
	CVector3 m_scale = CVector3::One;                       //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity;         //��]
	Player* m_player = nullptr;                             //�v���C���[�̃|�C���^
	Tombo* tombo = nullptr;                                 //�g���{�̃|�C���^
	Game2* game2 = nullptr;                                 //�X�e�[�W�Q�̃|�C���^
	CVector3 playerLen = CVector3::Zero;                    //�v���C���[�Ƃ̋���
	TomboAttackState* tomboAttackState = nullptr;           //�g���{�̍U���X�e�[�g

	int AttackChangeCount = 0;                              //�U���ύX�J�E���g
	int AttackTimer = 0;                                    //�U���^�C�}�[
	int Life = 200;                                         //HP
	int KidouTimer = 180;                                   //�����o���܂ł̃J�E���g
};

