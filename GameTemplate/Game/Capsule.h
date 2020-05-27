#pragma once
class Player;
class Game;
class Game2;
class CircleCharge;
class PlayerHpBer;
class StageNumber;

class Capsule : public IGameObject
{
public:
	Capsule();
	~Capsule();
	bool Start();
	void CapsuleGet(); //�J�v�Z���Q�b�g�֐�
	void Update();     //�X�V�֐�

	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                   //���W
	CVector3 m_scale = CVector3::One;                       //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity;         //��]
	Player* m_player = nullptr;                             //�v���C���[�̃|�C���^
	CircleCharge* m_charge = nullptr;                       //�T�[�N���Q�[�W�̃|�C���^
	PlayerHpBer* hpBer = nullptr;                           //HP�o�[�̃|�C���^
	StageNumber* stagenumber = nullptr;                     //�X�e�[�W�i���o�[�̃|�C���^
	CVector3 get = CVector3::Zero;                          //�J�v�Z���ƃv���C���[�Ƃ̋���
	prefab::CSoundSource* m_bgmSoundSource = nullptr;       //�T�E���h
};

