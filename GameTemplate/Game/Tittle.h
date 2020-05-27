#pragma once
class Tittle : public IGameObject
{
public:
	Tittle();
	~Tittle();
	bool Start();
	void Update();  //更新関数

	prefab::CSpriteRender* m_spriteRender = nullptr;   //タイトル用スプライト　背景
	prefab::CSpriteRender* m_spriteRender2 = nullptr;  //タイトル左帯スプライト
	prefab::CSpriteRender* m_spriteRender3 = nullptr;  //タイトル右帯スプライト
	prefab::CSpriteRender* m_spriteRender4 = nullptr;  //タイトル文字スプライト
	prefab::CSoundSource* m_bgmSoundSource = nullptr;  //サウンド
	prefab::CSoundSource* tittleSS;

	CVector3 haikeiPos = CVector3::Zero;    //背景座標
	CVector3 m_position = CVector3::Zero;   //タイトル左帯座標
	CVector3 m_position2 = CVector3::Zero;  //タイトル右帯座標
	CVector3 m_position3 = CVector3::Zero;  //タイトル文字座標
private:
	int AbottonHantei = 0;                 //Aボタンが押された判定
	
};

