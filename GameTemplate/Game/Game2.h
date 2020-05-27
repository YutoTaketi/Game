#pragma once
class Player;
class GameCameraPl;
class CircleCharge;
class StageNumber;
class PlayerHpBer;
class Kabuto;
class Kabuto2;
class Tombo;
class GameClear;
class GameOver;

class Game2 : public IGameObject
{
public:
	Game2();
	~Game2();
	bool Start();
	void Update();                              //更新関数
	//レベル
	CLevel m_level;                             //ステージレベル
	Player* m_player = nullptr;                //プレイヤーのポインタ
	GameCameraPl* m_gameCameraPl = nullptr;     //ゲームカメラのポインタ
	CircleCharge* m_circleCharge = nullptr;    //サークルチャージのポインタ
	StageNumber* stagenumber = nullptr;        //ステージナンバーのポインタ
	PlayerHpBer* m_HpBer = nullptr;           //HPバーのポインタ
	Tombo* m_tombo = nullptr;                 //トンボのポインタ
	prefab::CDirectionLight* m_directionLig = nullptr;   //ディレクションライト
	prefab::CSoundSource* game2SS = nullptr;             //サウンド

	int KabutoDethCount = 0;                   //カブトが死んだ数
	int BossFlag = 0;                           //ボスの出現フラグ
	int clearHantei = 0;                       //クリア判定
	int gameEndTimer = 0;                      //ゲームクリア画面への遷移タイマー
};

