#pragma once
class CircleCharge : public IGameObject
{
public:
	CircleCharge();
	~CircleCharge();
	bool Start();
	void Update();
	prefab::CSpriteRender* CircleWaku;
	
	prefab::CSpriteRender* CircleGage;
	CVector3 GagePos;


};

