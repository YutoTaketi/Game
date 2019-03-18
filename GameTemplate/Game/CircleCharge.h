#pragma once
class CircleCharge : public IGameObject
{
public:
	CircleCharge();
	~CircleCharge();
	bool Start();
	void Update();
	prefab::CSpriteRender* m_spriteRender;
	CVector3 m_position;

};

