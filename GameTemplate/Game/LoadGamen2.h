#pragma once
class StageNumber;
class LoadGamen2 : public IGameObject
{
public:
	LoadGamen2();
	~LoadGamen2();
	bool Start();
	void Update();  //�X�V�֐�

	int LoadTimer = 0;    //�J�ڂ���܂ł̃^�C�}�[
	prefab::CSpriteRender* m_spriteRender = nullptr; //�X�v���C�g

	StageNumber* stagenumber = nullptr; //�X�e�[�W�i���o�[
};

