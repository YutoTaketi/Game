#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class TomboAttackState;
class Tama;
class Game2;
class TomboJr;

class Tombo : public IGameObject
{
public:
	Tombo();
	~Tombo();
	bool Start();
	void Move();    //�ړ��֐�
	void Turn();    //��]�֐�
	void Attack();  //�U���֐�
	void Bunsin();  //���g�֐�
	void Hidan();   //��e�֐�
	void Deth();    //���S�֐�
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr; //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                  //���W
	CVector3 m_scale = CVector3::One;                      //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity;        //��]
	Player* m_player = nullptr;                            //�v���C���[�̃|�C���^
	CVector3 playerLen = CVector3::Zero;                   //�v���C���[�Ƃ̋���

	TomboAttackState* tomboAttackState = nullptr;          //�g���{�̍U���X�e�[�g
	Game2* game2 = nullptr;                                //game�̃|�C���^
	TomboJr* tomboJr[1] = { nullptr };                     //���g�̃|�C���^

	int AttackTimer = 0;                                   //�U���^�C�}�[
	int Life = 500;                                        //���C�t
	int AttackChangeCount = 0;                             //�U�����؂�ւ��܂ł̃J�E���g
	int bunsinHantei = 0;  //���g�̔���
	int bunsinStartTimer = 0;  //���g�J�n�^�C�}�[
};

