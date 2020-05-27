#pragma once
class Player;
class GameCameraPl;
class CircleCharge;
class StageNumber;
class PlayerHpBer;
class Kabuto;
class Kabuto2;
class Tombo;
class GameClear;
class GameOver;

class Game2 : public IGameObject
{
public:
	Game2();
	~Game2();
	bool Start();
	void Update();                              //�X�V�֐�
	//���x��
	CLevel m_level;                             //�X�e�[�W���x��
	Player* m_player = nullptr;                //�v���C���[�̃|�C���^
	GameCameraPl* m_gameCameraPl = nullptr;     //�Q�[���J�����̃|�C���^
	CircleCharge* m_circleCharge = nullptr;    //�T�[�N���`���[�W�̃|�C���^
	StageNumber* stagenumber = nullptr;        //�X�e�[�W�i���o�[�̃|�C���^
	PlayerHpBer* m_HpBer = nullptr;           //HP�o�[�̃|�C���^
	Tombo* m_tombo = nullptr;                 //�g���{�̃|�C���^
	prefab::CDirectionLight* m_directionLig = nullptr;   //�f�B���N�V�������C�g
	prefab::CSoundSource* game2SS = nullptr;             //�T�E���h

	int KabutoDethCount = 0;                   //�J�u�g�����񂾐�
	int BossFlag = 0;                           //�{�X�̏o���t���O
	int clearHantei = 0;                       //�N���A����
	int gameEndTimer = 0;                      //�Q�[���N���A��ʂւ̑J�ڃ^�C�}�[
};

