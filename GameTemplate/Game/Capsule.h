#pragma once
class Player;
class Game;
class Game2;
class CircleCharge;
class PlayerHpBer;
class StageNumber;

class Capsule : public IGameObject
{
public:
	Capsule();
	~Capsule();
	bool Start();
	void CapsuleGet(); //カプセルゲット関数
	void Update();     //更新関数

	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //スキンモデル
	CVector3 m_position = CVector3::Zero;                   //座標
	CVector3 m_scale = CVector3::One;                       //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;         //回転
	Player* m_player = nullptr;                             //プレイヤーのポインタ
	CircleCharge* m_charge = nullptr;                       //サークルゲージのポインタ
	PlayerHpBer* hpBer = nullptr;                           //HPバーのポインタ
	StageNumber* stagenumber = nullptr;                     //ステージナンバーのポインタ
	CVector3 get = CVector3::Zero;                          //カプセルとプレイヤーとの距離
	prefab::CSoundSource* m_bgmSoundSource = nullptr;       //サウンド
};

