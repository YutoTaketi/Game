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
	void Move();      //移動関数
	void Turn();      //回転関数
	void BeeAtack();  //攻撃関数
	void Deth();      //死亡関数
	void Update();    //更新関数

	

public:
	
	int m_timer = 0; //攻撃用のタイマー
	
	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //スキンモデル
	CVector3 m_position = CVector3::Zero;  //座標
	CVector3 m_scale = CVector3::One;      //拡大

	CQuaternion m_rotation = CQuaternion::Identity; //回転
	Player* m_player = nullptr; //プレイヤーのポインタ
	Game* game = nullptr;  //Gameのポインタ
	prefab::CSoundSource* m_bgmSoundSource = nullptr;  //サウンド
	CVector3 playerLen = CVector3::Zero;     //プレイヤーとの距離

	

};

