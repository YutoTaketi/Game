#pragma once
class BeeBallet;
class Bee3Ballet;
class BossSlash;
class BossBall;
class Player;
class StageNumber;
class KabutoBallet;
class Kabuto;
class TomboAttack1;
class TomboAttack2;

class PlayerHpBer : public IGameObject
{
public:
	PlayerHpBer();
	~PlayerHpBer();

	bool Start();
	void GageGensyou();
	void Update();

	prefab::CSpriteRender* HpWaku;                 //Hpゲージの枠

	prefab::CSpriteRender* HpGage;                 //Hpゲージ
	CVector3 BalletPlayer = CVector3::Zero;        //ハチの弾とプレイヤーとの距離
	CVector3 SlashPlayer = CVector3::Zero;         //カマキリの攻撃１とプレイヤーとの距離
	CVector3 BallPlayer = CVector3::Zero;          //カマキリの攻撃２とプレイヤーとの距離
	CVector3 Ballet3Player = CVector3::Zero;       //ハチ３の弾とプレイヤーとの距離
	CVector3 KabutoBalletPlayer = CVector3::Zero;  //カブトの弾とプレイヤーとの距離
	CVector3 TomboBeamPlayer = CVector3::Zero;     //トンボの攻撃１とプレイヤーとの距離
	CVector3 TomboBeam2Player = CVector3::Zero;    //トンボの攻撃2とプレイヤーとの距離
	CVector3 GagePos = CVector3::Zero;             //ゲージの座標
	float w = 290;                                 //ゲージの最大値

	StageNumber* stagenumber = nullptr;            //ステージナンバーのポインタ
};

