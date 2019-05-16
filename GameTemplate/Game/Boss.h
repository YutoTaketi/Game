#pragma once
class Player;
class Boss : public IGameObject
{
public:
	Boss();
	~Boss();

	bool Start();
	void Move();
	void Turn();
	void Atack();
	void Boost();
	void Hidan();
	void Deth();
	void Update();

	//アニメーションクリップ
	enum EnAnimationClip {
		enAnimationClip_Atack,
		enAnimationClip_Boost,
		enAnimationClip_num,
	};

	 
	CAnimationClip m_animationClip[enAnimationClip_num];
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;	//座標。
	CQuaternion m_rotation = CQuaternion::Identity;	//回転。
	CVector3 m_scale = CVector3::One;   //スケール
	 int life = 200; //ボスのライフ
	Player* m_player = nullptr;


};

