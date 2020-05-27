#pragma once
#include "Player.h"
#include "tkEngine/camera/tkSpringCamera.h"
class GameCameraPl : public IGameObject
{
public:
	GameCameraPl();
	~GameCameraPl();
	bool Start();
	void Update();  //�X�V�֐�

	//�����o�ϐ�
	Player* m_player;             //�v���C���[�̃|�C���^
	CVector3 m_toCameraPos;       //�J�����̍��W
	CSpringCamera m_springCamera; //�o�l�J����
};

