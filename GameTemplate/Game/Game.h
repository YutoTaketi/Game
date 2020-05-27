#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"

class Player;
class GameCameraPl;
class Stage;
class DemoCircle;
class DemoBall;
class Bee;
class Bee2;
class Capsule;
class SpornSinden;
class CircleCharge;
class GameClear;
class PlayerHpBer;
class Boss;  //������

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();        //�X�V�֐�
	int dethCount = 0;    //�n�`�����񂾐�
	int BossFlag = 0;    //�{�X�X�|�[���t���O
	int clearHantei = 0;   //�N���A����
	int DeleteHantei = false;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//�X�L�����f�������_���[�B
	prefab::CSoundSource* m_bgmSoundSource = nullptr;            //�T�E���h
	prefab::CSoundSource* gameSS;
	Player* m_player = nullptr;                                  //�v���C���[�̃|�C���^
	GameCameraPl* m_gameCameraPl = nullptr;                      //�Q�[���J�����̃|�C���^
	Stage* m_stage = nullptr;                                    //�X�e�[�W�̃|�C���^
	DemoCircle* m_demoCircle = nullptr;                          //�T�[�N���̃|�C���^
	DemoBall* m_demoBall = nullptr;                              //
	CircleCharge* m_circleCharge = nullptr;                      //�T�[�N���`���[�W�̃|�C���^
	PlayerHpBer* m_HpBer = nullptr;                              //Hp�o�[�̃|�C���^
	Boss* m_boss = nullptr;                                      //�{�X�̃|�C���^
	
	CLevel m_level;  //���x��

	int gameEndTimer = 0;                                        //�{�X������Ő��b��ɃN���A���
	prefab::CDirectionLight* m_directionLig = nullptr;           //�f�B���N�V�������C�g
};

