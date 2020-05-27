#pragma once
class Kabuto;
class Game2;
class Koukasasu;
class SpornBiru : public IGameObject
{
public:
	SpornBiru();
	~SpornBiru();
	bool Start();
	void Suporn(); //スポーン関数
	void Update(); //更新関数

	prefab::CSkinModelRender* m_skinModelRender = nullptr;  //スキンモデル
	CVector3 m_position = CVector3::Zero;                   //座標
	CVector3 m_scale = CVector3::One;                       //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;         //回転
	Game2* game2 = nullptr;                                 //game2のポインタ
	Koukasasu* koukasasu = nullptr;                         //コーカサスのポインタ
	int spornCount = 0;                                     //スポーンしたコーカサスの数
	int SpornTimer = 0;                                     //スポーンするまでのタイマー
	int i = 0;                                              //スポーンする間隔の調整変数

};

