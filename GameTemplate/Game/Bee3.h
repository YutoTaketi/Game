#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Game;
class Tama;

class Bee3 : public IGameObject
{
public:
	Bee3();
	~Bee3();
	bool Start();
	void Move();   //�ړ��֐�
	void Turn();   //��]�֐�
	void Attack(); //�U���֐�
	void Deth();   //���S�֐�
	void Update(); //�X�V�֐�

	int m_timer = 0;   //�U���p�^�C�}�[
	int StartUp = 0;   //���������p�̃^�C�}�[
	int Bee3dethCount = 0; //�n�`�����C���񂾂��̃J�E���g
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;  //���W
	CVector3 m_scale = CVector3::One;      //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity; //��]
	prefab::CSoundSource* m_bgmSoundSource = nullptr; //�T�E���h
	prefab::CEffect* effect;    //���S�G�t�F�N�g
	Player* m_player = nullptr; //�v���C���[�̃|�C���^
	Game* game = nullptr;       //Game�̃|�C���^
};

