#pragma once
class Player;
class Capsule;

class CircleCharge : public IGameObject
{
public:
	CircleCharge();
	~CircleCharge();
	bool Start();
	void GageGensyou(); //�Q�[�W�����֐�

	void GageCharge(); //�Q�[�W�`���[�W�֐�

	void Update();
	prefab::CSpriteRender* CircleWaku;  //�Q�[�W�g
	
	prefab::CSpriteRender* CircleGage;  //�Q�[�W
	CVector3 GagePos = CVector3::Zero;  //�Q�[�W���W
	float w = 290;                      //�Q�[�W�ő�l
	int capsuleget = 0;                 //�J�v�Z������������̔���



};

