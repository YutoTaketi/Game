#pragma once
class Player;
class CircleCharge : public IGameObject
{
public:
	CircleCharge();
	~CircleCharge();
	bool Start();
	void GageGensyou();
	void Update();
	prefab::CSpriteRender* CircleWaku;
	
	prefab::CSpriteRender* CircleGage;
	CVector3 GagePos;
	float w = 286;


};

