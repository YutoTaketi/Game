#pragma once
class Kabuto;
class Game2;
class Koukasasu;
class SpornBiru : public IGameObject
{
public:
	SpornBiru();
	~SpornBiru();
	bool Start();
	void Suporn(); //�X�|�[���֐�
	void Update(); //�X�V�֐�

	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                   //���W
	CVector3 m_scale = CVector3::One;                       //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity;         //��]
	Game2* game2 = nullptr;                                 //game2�̃|�C���^
	Koukasasu* koukasasu = nullptr;                         //�R�[�J�T�X�̃|�C���^
	int spornCount = 0;                                     //�X�|�[�������R�[�J�T�X�̐�
	int SpornTimer = 0;                                     //�X�|�[������܂ł̃^�C�}�[
	int i = 0;                                              //�X�|�[������Ԋu�̒����ϐ�

};

