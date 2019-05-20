#include "stdafx.h"
#include "PlayerHpBer.h"
#include "BeeBallet.h"
#include "BossSlash.h"
#include "Player.h"
#include "Game.h"


PlayerHpBer::PlayerHpBer()
{
}


PlayerHpBer::~PlayerHpBer()
{
	DeleteGO(HpWaku);
	DeleteGO(HpGage);
}

bool PlayerHpBer::Start()
{
	HpWaku = NewGO<prefab::CSpriteRender>(0);
	HpWaku->Init(L"sprite/hpmp_bar.dds", 300, 60);
	const CVector3 m_position = { -380.0, -250.0, 0.0 };
	HpWaku->SetPosition(m_position);

	HpGage = NewGO<prefab::CSpriteRender>(0);
	HpGage->Init(L"sprite/Hp.dds", w, 34);
	GagePos = { -236.0, -250.0, 0.0 };
	HpGage->SetPosition(GagePos);
	HpGage->SetPivot({ 1.0, 0.5 });

	return true;
}

void PlayerHpBer::GageGensyou()
{
	Game* game = FindGO<Game>("Game");
	Player* player = FindGO<Player>("Player");
	//PlayerHpBer* HpBer = FindGO<PlayerHpBer>("HpBer");
	if (player != nullptr) {
		/*QueryGOs<BeeBallet>("BeeBallet", [&](BeeBallet* beeBallet)->bool {
			BalletPlayer = beeBallet->m_position - player->m_position;
			if (BalletPlayer.Length() < 100.0f) {
				w = w - 5;
				HpGage->Init(L"sprite/Hp.dds", w, 34);
			
			}
			return true;
	     });*/
		
		//É{ÉXÇÃçUåÇÇ…Ç†Ç¡ÇΩÇÁHPÉQÅ[ÉWå∏è≠
		QueryGOs<BossSlash>("BossSlash", [&](BossSlash* bossSlash)->bool {
			SlashPlayer = bossSlash->m_position - player->m_position;
			if (SlashPlayer.Length() < 100.0f) {
				w = w - 10;
				HpGage->Init(L"sprite/Hp.dds", w, 34);

			}
			return true;
			});
	}
}

void PlayerHpBer::Update()
{
	GageGensyou();
	
}
	