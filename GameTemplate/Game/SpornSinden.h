#pragma once


class Game;
class Bee3;

class SpornSinden : public IGameObject
{
public:
	SpornSinden();
	~SpornSinden();

	bool Start();
	void BeeSporn();  //ハチのスポーン関数
	void BeeReSporn();//ハチのリスポーン関数
	void Update();    //更新関数

	int spornCount = 0; //スポーンした数
	int SpornTimer = 0; //
	prefab::CSkinModelRender* m_skinModelRender = nullptr; //スキンモデル
	CVector3 m_position = CVector3::Zero;                  //座標
	CVector3 m_scale = CVector3::One;                      //拡大率
	CQuaternion m_rotation = CQuaternion::Identity;        //回転
	Game* game = nullptr;                                  //gameのポインタ
	Bee3* bee3 = nullptr;                                  //ハチ３のポインタ
	int i = 0;
	
};

