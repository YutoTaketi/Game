#include "stdafx.h"
#include "GameCameraPl.h"


GameCameraPl::GameCameraPl()
{
}


GameCameraPl::~GameCameraPl()
{
}

bool GameCameraPl::Start()
{
	//�����_���王�_�܂ł̃x�N�g���ݒ�
	m_toCameraPos.Set(0.0f, 50.0f, 100.0f);
	m_player = FindGO<Player>("Player");

	MainCamera().SetNear(5.0f);
	MainCamera().SetFar(10000.0f);

	//�΂˃J�����̏�����
	m_springCamera.Init(
		MainCamera(),
		10000.0f,
		true,
		5.0f
	);
	return true;
}

void GameCameraPl::Update()
{
	//�J�����X�V
	//�����_�v�Z
	CVector3 target = m_player->m_position;
	target.y += 200.0f;
	target.z += 200.0f;

	CVector3 toCameraPosOld = m_toCameraPos;
	//�E�X�e�B�b�N�ŃJ�������񂷁B
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();
	//Y������̉�]
	CQuaternion qRot; 
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(m_toCameraPos);
	//X������̉�]
	CVector3 axisX;
	axisX.Cross(CVector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 2.0f * y);
	qRot.Multiply(m_toCameraPos);

	//��]���
	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.5f) {
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		m_toCameraPos = toCameraPosOld;
	}

	//���_���v�Z����B
	CVector3 pos = target + m_toCameraPos;
     //�΂˃J�����ɒ����_�A���_��ݒ肷��B
	m_springCamera.SetTarget(target);
	m_springCamera.SetPosition(pos);
	//�΂˃J�����X�V
	m_springCamera.Update();
}
