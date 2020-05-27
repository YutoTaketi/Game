#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"

class Player;
class Game;

class Bee2 : public IGameObject
{
public:
	Bee2();
	~Bee2();
	bool Start();
	void Move();      //移動処理
	void Turn();      //回転処理
	void BeeAtack();  //攻撃処理
	void Deth();      //死亡処理
	void Update();    //更新処理

	int m_timer = 0;   //攻撃用タイマー
	int moveTimer = 0; //移動用タイマー
	int moveState = 0; //移動用判定
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデル
	CVector3 m_position = CVector3::Zero;            //座標
	CVector3 m_scale = CVector3::One;                //拡大率
	//CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;  //回転
	Player* m_player = nullptr;                      //プレイヤーのポインタ
	Game* game = nullptr;                            //Gameのポインタ
	prefab::CSoundSource* m_bgmSoundSource = nullptr; //サウンド
	CVector3 playerLen = CVector3::Zero;              //プレイヤーとの距離
	

};

