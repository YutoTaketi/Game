#pragma once
class Player;
class Capsule;

class CircleCharge : public IGameObject
{
public:
	CircleCharge();
	~CircleCharge();
	bool Start();
	void GageGensyou(); //ゲージ減少関数

	void GageCharge(); //ゲージチャージ関数

	void Update();
	prefab::CSpriteRender* CircleWaku;  //ゲージ枠
	
	prefab::CSpriteRender* CircleGage;  //ゲージ
	CVector3 GagePos = CVector3::Zero;  //ゲージ座標
	float w = 290;                      //ゲージ最大値
	int capsuleget = 0;                 //カプセルを取ったかの判定



};

