#pragma once
class StageNumber;
class Tittle;
class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();
	void Update();  //�X�V�֐�

	int clearTimer = 0;
	prefab::CSpriteRender* m_spriteRender = nullptr;   //�N���A�w�i�X�v���C�g
	prefab::CSpriteRender* m_spriteStage = nullptr;    //�X�e�[�W�уX�v���C�g
	prefab::CSpriteRender* m_ClearObi = nullptr;       //�N���A�уX�v���C�g
	prefab::CSoundSource* m_bgmSoundSource = nullptr;  //�T�E���h
	prefab::CSoundSource* clearSS;
	StageNumber* stagenumber = nullptr;                //�X�e�[�W�i���o�[


	CVector3 spriteStagePos = CVector3::Zero;          //�X�e�[�W�э��W
	CVector3 clearobiPos = CVector3::Zero;             //�N���A�э��W
};

