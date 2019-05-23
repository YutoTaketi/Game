#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"

class Player;
class GameCameraPl;
class Stage;
class DemoCircle;
class DemoBall;
class Bee;
class Bee2;
class Capsule;
class CircleCharge;
class GameClear;
class PlayerHpBer;
class Boss;  //お試し

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	int dethCount = 0;
	int BossFlag = 0;    //ボススポーンフラグ
	int clearHantei = 0;
	int DeleteHantei = false;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
	prefab::CSoundSource* gameSS;
	Player* m_player = nullptr;
	GameCameraPl* m_gameCameraPl = nullptr;
	Stage* m_stage = nullptr;
	DemoCircle* m_demoCircle = nullptr;
	DemoBall* m_demoBall = nullptr;
	CircleCharge* m_circleCharge = nullptr;
	PlayerHpBer* m_HpBer = nullptr;
	Boss* m_boss = nullptr; //お試し
	/*Bee* m_bee = nullptr;*/
	CQuaternion m_rotation = CQuaternion::Identity;
	CLevel m_level;  //レベル

	int gameEndTimer = 0;  //ボスが死んで数秒後にクリア画面
};

