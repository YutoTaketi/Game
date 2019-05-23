#pragma once
class BeeBallet;
class BossSlash;
class BossBall;
class Player;
class PlayerHpBer : public IGameObject
{
public:
	PlayerHpBer();
	~PlayerHpBer();

	bool Start();
	void GageGensyou();
	void Update();

	prefab::CSpriteRender* HpWaku;

	prefab::CSpriteRender* HpGage;
	CVector3 BalletPlayer = CVector3::Zero;
	CVector3 SlashPlayer = CVector3::Zero;
	CVector3 BallPlayer = CVector3::Zero;
	CVector3 GagePos;
	float w = 286;
};

