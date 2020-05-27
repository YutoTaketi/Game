#include "stdafx.h"
#include "SpornBiru.h"
#include "Koukasasu.h"
#include "Game2.h"


SpornBiru::SpornBiru()
{
}


SpornBiru::~SpornBiru()
{
	DeleteGO(m_skinModelRender);
	DeleteGOs("Koukasasu");
}

bool SpornBiru::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/SpornBiru.cmo");
	return true;
}

void SpornBiru::Suporn()
{
	if (game2 == nullptr) {
		game2 = FindGO<Game2>("Game2");
	}
	else {
		if (game2->BossFlag == 1) {
			SpornTimer++;
			//�R�[�J�T�X���R�̏o��
			if (SpornTimer == 80 + i && spornCount <= 3) {
				koukasasu = NewGO<Koukasasu>(0, "Koukasasu");
				koukasasu->m_position = m_position;
				koukasasu->m_position.y += 500.0;
				spornCount += 1;
				SpornTimer = 0;
				i = 200;
				
			}
			
		}
	}
}

void SpornBiru::Update()
{
	Suporn();
	//��萔���񂾂�A�ǉ��ŃJ�u�g���X�|�[��
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
}
