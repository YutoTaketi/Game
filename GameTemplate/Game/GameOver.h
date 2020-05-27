#pragma once
class StageNumber;
class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();

	bool Start();
	void Update();  //更新関数

	prefab::CSpriteRender* m_spriteRender = nullptr;   //背景スプライト
	prefab::CSpriteRender* m_gameObi = nullptr;        //ゲーム帯スプライト
	prefab::CSpriteRender* m_overObi = nullptr;        //オーバー帯スプライト
	prefab::CSoundSource* m_bgmSoundSource = nullptr;  //サウンド
	prefab::CSoundSource* overSS;
	StageNumber* stagenumber = nullptr;                //ステージナンバーのポインタ
	CVector3 m_gameObiPos = CVector3::Zero;            //ゲーム帯座標
	CVector3 m_overobiPos = CVector3::Zero;            //オーバー帯座標
	int overTimer = 0;                                 //タイトルに戻るまでのタイマー
};

