#pragma once
class Setumei : public IGameObject
{
public:
	Setumei();
	~Setumei();
	bool Start();
	void Update();

	prefab::CSpriteRender* m_spriteRender = nullptr; //�w�i�X�v���C�g
	CVector3 m_position = CVector3::Zero;            //���W
	prefab::CSpriteRender* m_spriteRender2 = nullptr;//�����X�v���C�g

	int SeniTimaer = 0;                               //�J�ڂ���܂ł̃^�C�}�[
};

