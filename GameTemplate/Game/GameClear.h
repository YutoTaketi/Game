#pragma once
class StageNumber;
class Tittle;
class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();
	void Update();  //更新関数

	int clearTimer = 0;
	prefab::CSpriteRender* m_spriteRender = nullptr;   //クリア背景スプライト
	prefab::CSpriteRender* m_spriteStage = nullptr;    //ステージ帯スプライト
	prefab::CSpriteRender* m_ClearObi = nullptr;       //クリア帯スプライト
	prefab::CSoundSource* m_bgmSoundSource = nullptr;  //サウンド
	prefab::CSoundSource* clearSS;
	StageNumber* stagenumber = nullptr;                //ステージナンバー


	CVector3 spriteStagePos = CVector3::Zero;          //ステージ帯座標
	CVector3 clearobiPos = CVector3::Zero;             //クリア帯座標
};

