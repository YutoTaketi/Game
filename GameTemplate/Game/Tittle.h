#pragma once
class Tittle : public IGameObject
{
public:
	Tittle();
	~Tittle();
	bool Start();
	void Update();  //�X�V�֐�

	prefab::CSpriteRender* m_spriteRender = nullptr;   //�^�C�g���p�X�v���C�g�@�w�i
	prefab::CSpriteRender* m_spriteRender2 = nullptr;  //�^�C�g�����уX�v���C�g
	prefab::CSpriteRender* m_spriteRender3 = nullptr;  //�^�C�g���E�уX�v���C�g
	prefab::CSpriteRender* m_spriteRender4 = nullptr;  //�^�C�g�������X�v���C�g
	prefab::CSoundSource* m_bgmSoundSource = nullptr;  //�T�E���h
	prefab::CSoundSource* tittleSS;

	CVector3 haikeiPos = CVector3::Zero;    //�w�i���W
	CVector3 m_position = CVector3::Zero;   //�^�C�g�����э��W
	CVector3 m_position2 = CVector3::Zero;  //�^�C�g���E�э��W
	CVector3 m_position3 = CVector3::Zero;  //�^�C�g���������W
private:
	int AbottonHantei = 0;                 //A�{�^���������ꂽ����
	
};

