#pragma once
class StageNumber;
class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();

	bool Start();
	void Update();  //�X�V�֐�

	prefab::CSpriteRender* m_spriteRender = nullptr;   //�w�i�X�v���C�g
	prefab::CSpriteRender* m_gameObi = nullptr;        //�Q�[���уX�v���C�g
	prefab::CSpriteRender* m_overObi = nullptr;        //�I�[�o�[�уX�v���C�g
	prefab::CSoundSource* m_bgmSoundSource = nullptr;  //�T�E���h
	prefab::CSoundSource* overSS;
	StageNumber* stagenumber = nullptr;                //�X�e�[�W�i���o�[�̃|�C���^
	CVector3 m_gameObiPos = CVector3::Zero;            //�Q�[���э��W
	CVector3 m_overobiPos = CVector3::Zero;            //�I�[�o�[�э��W
	int overTimer = 0;                                 //�^�C�g���ɖ߂�܂ł̃^�C�}�[
};

