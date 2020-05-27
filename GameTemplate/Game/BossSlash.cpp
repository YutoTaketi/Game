#include "stdafx.h"
#include "BossSlash.h"



BossSlash::BossSlash()
{
}


BossSlash::~BossSlash()
{
	DeleteGO(effect);
}

bool BossSlash::Start()
{
	effect = NewGO<prefab::CEffect>(0);
	//�G�t�F�N�g���Đ�
	effect->Play(L"effect/Slash.efk");
	m_scale = { 3.0, 3.0, 3.0 };
	return true;
}

void BossSlash::Update()
{
	m_position += m_moveSpeed;
	effect->SetPosition(m_position);
	effect->SetScale(m_scale);
	effect->SetRotation(m_rotation);
	m_timer++;
	//����
	if (m_timer == 120) {
		DeleteGO(this);
	}
}
