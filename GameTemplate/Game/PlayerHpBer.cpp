#include "stdafx.h"
#include "PlayerHpBer.h"
#include "BeeBallet.h"
#include "BossSlash.h"
#include "BossBall.h"
#include "Bee3Ballet.h"
#include "Player.h"
#include "Game.h"
#include "Game2.h"
#include "TomboAttack1.h"
#include "TomboAttack2.h"
#include "KabutoBallet.h"
#include "Kabuto.h"
#include "StageNumber.h"


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
	HpWaku->Init(L"sprite/HpMpbar.dds", 424, 150);
	const CVector3 m_position = { -380.0, -240.0, 0.0 };
	HpWaku->SetPosition(m_position);


	HpGage = NewGO<prefab::CSpriteRender>(0);
	HpGage->Init(L"sprite/Hp.dds", w, 48);
	GagePos = { -245.0, -250.0, 0.0 };
	//GagePos = { 0.0f, 0.0f, 0.0f };
	HpGage->SetPosition(GagePos);
	HpGage->SetPivot({ 1.0, 0.5 });

	return true;
}

void PlayerHpBer::GageGensyou()
{
	stagenumber = &StageNumber::GetInstance();
	//ステージ１のダメージ判定
	if (stagenumber->GetStageNumber() == StageNumber::enState_Stage1) {
		Game* game = FindGO<Game>("Game");
		Player* player = FindGO<Player>("Player");
		
		if (player != nullptr) {
			//ハチの弾の判定
			QueryGOs<BeeBallet>("BeeBallet", [&](BeeBallet* beeBallet)->bool {
				BalletPlayer = beeBallet->m_position - player->m_position;
				if (BalletPlayer.Length() < 100.0f) {
					w = w - 0.5;
					HpGage->Init(L"sprite/Hp.dds", w, 48);
					prefab::CSoundSource* playerDamegess;
					playerDamegess = NewGO<prefab::CSoundSource>(0);
					playerDamegess->Init(L"sound/PlayerHit.wav");
					playerDamegess->SetVolume(2.0);
					playerDamegess->Play(false);

				}
				return true;
			});
			//ハチ３の弾の判定
			QueryGOs<Bee3Ballet>("Bee3Ballet", [&](Bee3Ballet* bee3Ballet)->bool {
				Ballet3Player = bee3Ballet->m_position - player->m_position;
				if (Ballet3Player.Length() < 100.0f) {
					w = w - 0.5;
					HpGage->Init(L"sprite/Hp.dds", w, 48);
					prefab::CSoundSource* playerDamegess;
					playerDamegess = NewGO<prefab::CSoundSource>(0);
					playerDamegess->Init(L"sound/PlayerHit.wav");
					playerDamegess->SetVolume(2.0);
					playerDamegess->Play(false);

				}
				return true;
				});
			//ボスの攻撃にあったらHPゲージ減少
			//第一段階
			QueryGOs<BossSlash>("BossSlash", [&](BossSlash* bossSlash)->bool {
				SlashPlayer = bossSlash->m_position - player->m_position;
				if (SlashPlayer.Length() < 100.0f) {
					w = w - 2;
					HpGage->Init(L"sprite/Hp.dds", w, 48);
					prefab::CSoundSource* playerDamegess;
					playerDamegess = NewGO<prefab::CSoundSource>(0);
					playerDamegess->Init(L"sound/PlayerHit.wav");
					playerDamegess->SetVolume(2.0);
					playerDamegess->Play(false);
				}
				return true;
				});

			//第二段階
			QueryGOs<BossBall>("Ball", [&](BossBall* bossBall)->bool {
				BallPlayer = bossBall->m_position - player->m_position;
				if (BallPlayer.Length() < 100.0f) {
					w = w - 3;
					HpGage->Init(L"sprite/Hp.dds", w, 48);
					prefab::CSoundSource* playerDamegess;
					playerDamegess = NewGO<prefab::CSoundSource>(0);
					playerDamegess->Init(L"sound/PlayerHit.wav");
					playerDamegess->SetVolume(2.0);
					playerDamegess->Play(false);
				}
				return true;
			});

		}
	}

	//ステージ
	if (stagenumber->GetStageNumber() == StageNumber::enState_Stage2)
	{
		Game2* game2 = FindGO<Game2>("Game2");
		Player* player = FindGO<Player>("Player");
		//カブトの弾との判定
		QueryGOs<Kabuto>("Kabuto", [&](Kabuto* kabuto)->bool {
			KabutoBalletPlayer = kabuto->m_position - player->m_position;
			if (KabutoBalletPlayer.Length() < 50.0f) {
				w = w - 0.5;
				HpGage->Init(L"sprite/Hp.dds", w, 48);
				prefab::CSoundSource* playerDamegess;
				playerDamegess = NewGO<prefab::CSoundSource>(0);
				playerDamegess->Init(L"sound/PlayerHit.wav");
				playerDamegess->SetVolume(2.0);
				playerDamegess->Play(false);
			}
			return true;
			});
		     
 			QueryGOs<KabutoBallet>("KabutoBallet", [&](KabutoBallet* kabutoBallet)->bool {
				KabutoBalletPlayer = kabutoBallet->m_position - player->m_position;
				if (KabutoBalletPlayer.Length() < 50.0f) {
					w = w - 1;
					HpGage->Init(L"sprite/Hp.dds", w, 48);
					prefab::CSoundSource* playerDamegess;
					playerDamegess = NewGO<prefab::CSoundSource>(0);
					playerDamegess->Init(L"sound/PlayerHit.wav");
					playerDamegess->SetVolume(2.0);
					playerDamegess->Play(false);
				}
				return true;
			});
			//トンボの攻撃１の判定
			QueryGOs<TomboAttack1>("Attack1", [&](TomboAttack1* tomboAttack1)->bool {
				TomboBeamPlayer = tomboAttack1->m_position - player->m_position;
				if (TomboBeamPlayer.Length() < 50.0f) {
					w = w - 1;
					HpGage->Init(L"sprite/Hp.dds", w, 48);
					prefab::CSoundSource* playerDamegess;
					playerDamegess = NewGO<prefab::CSoundSource>(0);
					playerDamegess->Init(L"sound/PlayerHit.wav");
					playerDamegess->SetVolume(2.0);
					playerDamegess->Play(false);
				}
				return true;
			});
			//トンボの攻撃２との判定
			QueryGOs<TomboAttack2>("Attack2", [&](TomboAttack2* tomboAttack2)->bool {
				TomboBeam2Player = tomboAttack2->m_position - player->m_position;
				if (TomboBeam2Player.Length() < 1000.0f) {
					w -= 30 * GameTime().GetFrameDeltaTime();
					//w = w - 1.5;
					HpGage->Init(L"sprite/Hp.dds", w, 48);
					prefab::CSoundSource* playerDamegess;
					playerDamegess = NewGO<prefab::CSoundSource>(0);
					playerDamegess->Init(L"sound/PlayerHit.wav");
					playerDamegess->SetVolume(2.0);
					playerDamegess->Play(false);
				}
				return true;
				});
		//}
	}
}

void PlayerHpBer::Update()
{
	GageGensyou();
	
}
	