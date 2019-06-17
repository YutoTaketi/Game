#include "stdafx.h"
#include "Tittle.h"
#include "Game.h"
#include "LoadGamen.h"


Tittle::Tittle()
{
}


Tittle::~Tittle()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_bgmSoundSource);
}

bool Tittle::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Start.dds", 1600.0f, 1200.0f);
	//prefab::CSoundSource* tittleSS;
	tittleSS = NewGO<prefab::CSoundSource>(0);
	tittleSS->Init(L"sound/TitleSound.wav");
	tittleSS->SetVolume(0.5);
	tittleSS->Play(false);
	return true;
}

void Tittle::Update()
{
	
	if (Pad(0).IsTrigger(enButtonA)) {
		//ƒNƒŠƒbƒN‰¹‚ð—¬‚·
		prefab::CSoundSource* Ass;
		Ass = NewGO<prefab::CSoundSource>(0);
		Ass->Init(L"sound/click.wav");
		Ass->Play(false);
		Ass->SetVolume(2.0);

		//NewGO<Game>(0, "Game");
		NewGO<LoadGamen>(0, "LoadGamen");
		DeleteGO(this);
		DeleteGO(tittleSS);
	}
}
