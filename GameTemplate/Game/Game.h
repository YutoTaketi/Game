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
class SpornSinden;
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
	void Update();        //更新関数
	int dethCount = 0;    //ハチが死んだ数
	int BossFlag = 0;    //ボススポーンフラグ
	int clearHantei = 0;   //クリア判定
	int DeleteHantei = false;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	prefab::CSoundSource* m_bgmSoundSource = nullptr;            //サウンド
	prefab::CSoundSource* gameSS;
	Player* m_player = nullptr;                                  //プレイヤーのポインタ
	GameCameraPl* m_gameCameraPl = nullptr;                      //ゲームカメラのポインタ
	Stage* m_stage = nullptr;                                    //ステージのポインタ
	DemoCircle* m_demoCircle = nullptr;                          //サークルのポインタ
	DemoBall* m_demoBall = nullptr;                              //
	CircleCharge* m_circleCharge = nullptr;                      //サークルチャージのポインタ
	PlayerHpBer* m_HpBer = nullptr;                              //Hpバーのポインタ
	Boss* m_boss = nullptr;                                      //ボスのポインタ
	
	CLevel m_level;  //レベル

	int gameEndTimer = 0;                                        //ボスが死んで数秒後にクリア画面
	prefab::CDirectionLight* m_directionLig = nullptr;           //ディレクションライト
};

