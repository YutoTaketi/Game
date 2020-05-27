#pragma once
#include "Player.h"
#include "tkEngine/camera/tkSpringCamera.h"
class GameCameraPl : public IGameObject
{
public:
	GameCameraPl();
	~GameCameraPl();
	bool Start();
	void Update();  //更新関数

	//メンバ変数
	Player* m_player;             //プレイヤーのポインタ
	CVector3 m_toCameraPos;       //カメラの座標
	CSpringCamera m_springCamera; //バネカメラ
};

