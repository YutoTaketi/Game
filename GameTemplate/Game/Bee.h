#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"

class Player;
class Game;

class Bee : public IGameObject
{
public:
	Bee();
	~Bee();

	bool Start();
	void Move();
	void Turn();
	void BeeAtack();
	void Deth();
	void Update();
private:
	const int balletCount = 3;
	

public:
	
	int m_timer = 0;
	//int beeDeth = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	//CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	Player* m_player = nullptr;
	Game* game = nullptr;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;

	//CCharacterController m_charaCon;		//キャラクターコントローラー。

};

