#include "stdafx.h"
#include "Stage.h"


Stage::Stage()
{
}


Stage::~Stage()
{
}

bool Stage::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Demo.cmo");
	//CQuaternion qRot;
	//qRot.SetRotationDeg(CVector3::AxisY, 0.0f);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetShadowReceiverFlag(true);
	m_skinModelRender->SetShadowCasterFlag(true);
	//CVector3 pos = { 0.0f, -20.0f, 0.0f };
	m_skinModelRender->SetPosition(m_position);
	//CVector3 scale = { 2.5f, 2.5f, 2.5f };
	m_skinModelRender->SetScale(m_scale);
	m_phyStaticObject.CreateMesh(m_position, m_rotation, m_scale, m_skinModelRender);
	return true;
}