#include "stdafx.h"
#include "Tama.h"
#include "GameCameraPl.h"
#include "Player.h"


Tama::Tama()
{
}


Tama::~Tama()
{
	DeleteGO(m_skinModelRender);
}

bool Tama::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Tama.cmo");
	m_scale = { 0.25f, 0.25f, 0.25f };
	//m_skinModelRender->SetScale(m_scale);
	/*prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	CVector3 emitPos = m_position;
	CVector3 emitScale = {2.0, 2.0, 2.0};
	effect->SetPosition(emitPos);
	effect->SetScale(emitScale);*/
	Attack();
	return true;
}

void Tama::Attack()
{
	player = FindGO<Player>("Player");
	CVector3 Chramae = { 0, 0, 1 };
	//�L�����̉�]���Ă��Ȃ��Ƃ��̑O�x�N�g���ɁA
	//�L�����̉�]�N�H�[�^�j�I����K�p���āA�񂷁B
	player->m_rotation.Apply(Chramae);
	m_moveSpeed = Chramae * 10.0;
	
}

void Tama::Update()
{

	m_timer++;
	//Attack();
	//�G�t�F�N�g�̃C���X�^���X�𐶐�
	/*prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	effect->Play(L"effect/Tama.efk");
	CVector3 emitPos = m_position;
	CVector3 emitScale = {2.0, 2.0, 2.0};
	effect->SetPosition(emitPos);
	effect->SetScale(emitScale);*/

	m_position += m_moveSpeed;
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(m_scale);
	if (m_timer == 50)
	{
		DeleteGO(this);
		//DeleteGO(effect);
	}
	
}