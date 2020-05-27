#pragma once
class BeeBallet;
class Bee3Ballet;
class BossSlash;
class BossBall;
class Player;
class StageNumber;
class KabutoBallet;
class Kabuto;
class TomboAttack1;
class TomboAttack2;

class PlayerHpBer : public IGameObject
{
public:
	PlayerHpBer();
	~PlayerHpBer();

	bool Start();
	void GageGensyou();
	void Update();

	prefab::CSpriteRender* HpWaku;                 //Hp�Q�[�W�̘g

	prefab::CSpriteRender* HpGage;                 //Hp�Q�[�W
	CVector3 BalletPlayer = CVector3::Zero;        //�n�`�̒e�ƃv���C���[�Ƃ̋���
	CVector3 SlashPlayer = CVector3::Zero;         //�J�}�L���̍U���P�ƃv���C���[�Ƃ̋���
	CVector3 BallPlayer = CVector3::Zero;          //�J�}�L���̍U���Q�ƃv���C���[�Ƃ̋���
	CVector3 Ballet3Player = CVector3::Zero;       //�n�`�R�̒e�ƃv���C���[�Ƃ̋���
	CVector3 KabutoBalletPlayer = CVector3::Zero;  //�J�u�g�̒e�ƃv���C���[�Ƃ̋���
	CVector3 TomboBeamPlayer = CVector3::Zero;     //�g���{�̍U���P�ƃv���C���[�Ƃ̋���
	CVector3 TomboBeam2Player = CVector3::Zero;    //�g���{�̍U��2�ƃv���C���[�Ƃ̋���
	CVector3 GagePos = CVector3::Zero;             //�Q�[�W�̍��W
	float w = 290;                                 //�Q�[�W�̍ő�l

	StageNumber* stagenumber = nullptr;            //�X�e�[�W�i���o�[�̃|�C���^
};

