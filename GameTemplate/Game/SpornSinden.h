#pragma once


class Game;
class Bee3;

class SpornSinden : public IGameObject
{
public:
	SpornSinden();
	~SpornSinden();

	bool Start();
	void BeeSporn();  //�n�`�̃X�|�[���֐�
	void BeeReSporn();//�n�`�̃��X�|�[���֐�
	void Update();    //�X�V�֐�

	int spornCount = 0; //�X�|�[��������
	int SpornTimer = 0; //
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                  //���W
	CVector3 m_scale = CVector3::One;                      //�g�嗦
	CQuaternion m_rotation = CQuaternion::Identity;        //��]
	Game* game = nullptr;                                  //game�̃|�C���^
	Bee3* bee3 = nullptr;                                  //�n�`�R�̃|�C���^
	int i = 0;
	
};

