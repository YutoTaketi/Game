#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Game;
class Tama;

class Bee3 : public IGameObject
{
public:
	Bee3();
	~Bee3();
	bool Start();
	void Move();   //移動関数
	void Turn();   //回転関数
	void Attack(); //攻撃関数
	void Deth();   //死亡関数
	void Update(); //更新関数

	int m_timer = 0;   //攻撃用タイマー
	int StartUp = 0;   //動きだし用のタイマー
	int Bee3dethCount = 0; //ハチが何匹死んだかのカウント
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;  //座標
	CVector3 m_scale = CVector3::One;      //拡大率
	CQuaternion m_rotation = CQuaternion::Identity; //回転
	prefab::CSoundSource* m_bgmSoundSource = nullptr; //サウンド
	prefab::CEffect* effect;    //死亡エフェクト
	Player* m_player = nullptr; //プレイヤーのポインタ
	Game* game = nullptr;       //Gameのポインタ
};

