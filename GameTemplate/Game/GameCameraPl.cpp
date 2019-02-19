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
	//注視点から視点までのベクトル設定
	m_toCameraPos.Set(0.0f, 50.0f, 100.0f);
	m_player = FindGO<Player>("Player");

	MainCamera().SetNear(5.0f);
	MainCamera().SetFar(10000.0f);

	//ばねカメラの初期化
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
	//カメラ更新
	//注視点計算
	CVector3 target = m_player->m_position;
	target.y += 200.0f;
	target.z += 200.0f;

	CVector3 toCameraPosOld = m_toCameraPos;
	//右スティックでカメラを回す。
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();
	//Y軸周りの回転
	CQuaternion qRot; 
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(m_toCameraPos);
	//X軸周りの回転
	CVector3 axisX;
	axisX.Cross(CVector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 2.0f * y);
	qRot.Multiply(m_toCameraPos);

	//回転上限
	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.5f) {
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		m_toCameraPos = toCameraPosOld;
	}

	//視点を計算する。
	CVector3 pos = target + m_toCameraPos;
     //ばねカメラに注視点、視点を設定する。
	m_springCamera.SetTarget(target);
	m_springCamera.SetPosition(pos);
	//ばねカメラ更新
	m_springCamera.Update();
}
