#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class Tama : public IGameObject
{
public:
	Tama();
	~Tama();
	bool Start();
	void Attack(); //�U���֐�
	void Update(); //�X�V�֐�

	Player* player = nullptr; //�v���C���[�̃|�C���^
	int m_timer = 0;          //
	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //�X�L�����f��
	CVector3 m_position = CVector3::Zero;                   //���W
	CVector3 m_moveSpeed = CVector3::Zero;                  //�ړ����x
	CVector3 m_scale = CVector3::Zero;                      //�g�嗦
};

