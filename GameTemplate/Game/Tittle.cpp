#include "stdafx.h"
#include "Tittle.h"
#include "Game.h"
#include "LoadGamen.h"
#include "Setumei.h"


Tittle::Tittle()
{
}


Tittle::~Tittle()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteRender2);
	DeleteGO(m_spriteRender3);
	DeleteGO(m_spriteRender4);
	DeleteGO(m_bgmSoundSource);
}

bool Tittle::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Tittle.dds", 1400.0f, 1200.0f);
	haikeiPos.x = 30.0f;
	m_spriteRender2 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender2->Init(L"sprite/Tittle2.dds", 1300.0f, 700.0f);
	//m_position.x = -300.0f;
	m_position.x += 0.0f;
	m_position.y -= 15.0f;

	m_spriteRender3 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender3->Init(L"sprite/Tittle3.dds", 1300.0f, 700.0f);
	m_position2.x -= 0.0f;
	m_position2.y -= 15.0f;

	m_spriteRender4 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender4->Init(L"sprite/Gurabisu.dds", 700.0f, 700.0f);
	//m_position3.y += 50.0f;  //丁度いい
	m_position3.y += 400.0f;  //スタート地点
	//prefab::CSoundSource* tittleSS;
	tittleSS = NewGO<prefab::CSoundSource>(0);
	tittleSS->Init(L"sound/TitleSound.wav");
	tittleSS->SetVolume(0.5);
	tittleSS->Play(false);
	return true;
}

void Tittle::Update()
{
	//グラビスの移動
	if (m_position3.y > 60.0f)
	{
		m_position3.y -= 2;
	}
	
	if (Pad(0).IsTrigger(enButtonA)) {
		//クリック音を流す
		prefab::CSoundSource* Ass;
		Ass = NewGO<prefab::CSoundSource>(0);
		Ass->Init(L"sound/click.wav");
		Ass->Play(false);
		Ass->SetVolume(2.0);
		AbottonHantei = 1;
		//NewGO<Game>(0, "Game");
		//NewGO<LoadGamen>(0, "LoadGamen");
		//DeleteGO(this);
		//DeleteGO(tittleSS);
	}

	if (m_position.x > -450.0f && AbottonHantei == 1)
	{
		m_position.x -= 10.0f;
	}
	if (m_position2.x < 450.0f && AbottonHantei == 1)
	{
	   m_position2.x += 10.0f;
	}

	//Aボタンが押された時の動作終了後、
	//説明画面に移る
	if (m_position.x <= -450 && m_position2.x >= 450 && AbottonHantei == 1) {
		
		
		NewGO<Setumei>(0, "Setumei");
		DeleteGO(this);
		DeleteGO(tittleSS);
		AbottonHantei = 0;
	}
	m_spriteRender->SetPosition(haikeiPos);
	m_spriteRender2->SetPosition(m_position);
	m_spriteRender3->SetPosition(m_position2);
	m_spriteRender4->SetPosition(m_position3);
}
