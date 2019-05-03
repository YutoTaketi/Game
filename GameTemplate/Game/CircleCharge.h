#pragma once
class Player;
class Capsule;

class CircleCharge : public IGameObject
{
public:
	CircleCharge();
	~CircleCharge();
	bool Start();
	void GageGensyou();

	void GageCharge();

	void Update();
	prefab::CSpriteRender* CircleWaku;
	
	prefab::CSpriteRender* CircleGage;
	CVector3 GagePos;
	float w = 286;
	int capsuleget = 0;



};

