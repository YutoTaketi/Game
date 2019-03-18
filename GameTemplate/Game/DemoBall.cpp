#include "stdafx.h"
#include "DemoBall.h"


DemoBall::DemoBall()
{
}


DemoBall::~DemoBall()
{
}

bool DemoBall::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/DemoBall.cmo");
	
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 0.0f);
	m_skinModelRender->SetRotation(qRot);
	m_skinModelRender->SetShadowReceiverFlag(true);
	m_skinModelRender->SetShadowCasterFlag(true);
	CVector3 pos = { 0.0f, -20.0f, 0.0f };
	m_skinModelRender->SetPosition(pos);
	CVector3 scale = { 15.0f, 15.0f, 15.0f };
	m_skinModelRender->SetScale(scale);
	m_phyStaticObject.CreateMesh(pos, qRot, scale, m_skinModelRender);
	return true;
}
