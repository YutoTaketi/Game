#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Game2;
class Tama;
class Koukasasu : public IGameObject
{
public:
	Koukasasu();
	~Koukasasu();

	bool Start();
	void Move();  //移動関数
	void Turn();  //回転関数
	void Attack();//攻撃関数
	void Deth();  //死亡関数
	void Update();//更新関数

	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデル
	CVector3 m_position = CVector3::Zero;                  //座標
	CVector3 m_scale = CVector3::One;                      //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;        //回転

	prefab::CSoundSource* m_bgmSoundSource = nullptr;      //サウンド
	prefab::CEffect* effect;                               //エフェクト
	Player* m_player = nullptr;                            //プレイヤーのポインタ
	Game2* game2 = nullptr;                                //Game2のポインタ
	int StartUp = 0;                                       //動きだすまでのカウント
	int m_timer = 0;                                       //攻撃の間隔タイマー
};

