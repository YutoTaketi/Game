#pragma once

class LoadGamen : public IGameObject
{
public:
	LoadGamen();
	~LoadGamen();
	bool Start();
	void Update();       //�X�V�֐�
	int LoadTimer = 0;  //�J�ڂ���܂ł̃^�C�}�[
	prefab::CSpriteRender* m_spriteRender = nullptr; //�X�v���C�g
	
};

