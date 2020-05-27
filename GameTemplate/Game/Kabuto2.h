#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"



class Player;
class Tama;
class Game2;

class Kabuto2 : public IGameObject
{
public:
	Kabuto2();
	~Kabuto2();
	bool Start();
	void Move();   //�ړ����x
	void Turn();   //��]�֐�
	void Attack(); //�U���֐�
	void Deth();   //���S�֐�
	void Update(); //�X�V�֐�

	prefab::CSkinModelRender* m_skinModelRender = nullptr; //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                  //���W
	CVector3 m_scale = CVector3::One;                      //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity;        //��]
	Player* m_player = nullptr;                            //�v���C���[�̃|�C���^
	CVector3 playerLen = CVector3::Zero;                   //�v���C���[�Ƃ̋���
	Game2* game2 = nullptr;                                //game2�̃|�C���^

	int AttackTimer = 0;                                   //�U������Ԋu�^�C�}�[
	int TossinHantei = 0;                                  //�ːi���邩�̔���
	int TossinStopTimer = 0;                               //�ːi���I���܂ł̃^�C�}�[
	int moveTimer = 0;                                     //�ړ��p�^�C�}�[
	int moveState = 0;                                     //���������ړ��̃X�e�[�g
};
