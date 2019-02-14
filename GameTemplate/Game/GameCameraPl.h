#pragma once
#include "Player.h"
#include "tkEngine/camera/tkSpringCamera.h"
class GameCameraPl : public IGameObject
{
public:
	GameCameraPl();
	~GameCameraPl();
	bool Start();
	void Update();

	//メンバ変数
	Player* m_player;
	CVector3 m_toCameraPos;
	CSpringCamera m_springCamera; //バネカメラ
};

