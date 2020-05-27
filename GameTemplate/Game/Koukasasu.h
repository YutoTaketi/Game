#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Game2;
class Tama;
class Koukasasu : public IGameObject
{
public:
	Koukasasu();
	~Koukasasu();

	bool Start();
	void Move();  //�ړ��֐�
	void Turn();  //��]�֐�
	void Attack();//�U���֐�
	void Deth();  //���S�֐�
	void Update();//�X�V�֐�

	prefab::CSkinModelRender* m_skinModelRender = nullptr; //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                  //���W
	CVector3 m_scale = CVector3::One;                      //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity;        //��]

	prefab::CSoundSource* m_bgmSoundSource = nullptr;      //�T�E���h
	prefab::CEffect* effect;                               //�G�t�F�N�g
	Player* m_player = nullptr;                            //�v���C���[�̃|�C���^
	Game2* game2 = nullptr;                                //Game2�̃|�C���^
	int StartUp = 0;                                       //���������܂ł̃J�E���g
	int m_timer = 0;                                       //�U���̊Ԋu�^�C�}�[
};

