#pragma once
class Player;
class Game;
class Game2;
class CircleCharge;
class PlayerHpBer;
class StageNumber;

class Capsule : public IGameObject
{
public:
	Capsule();
	~Capsule();
	bool Start();
	void CapsuleGet();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_scale = CVector3::One;
	CQuaternion m_rotation = CQuaternion::Identity;
	Player* m_player = nullptr;
	CircleCharge* m_charge = nullptr;
	PlayerHpBer* hpBer = nullptr;
	StageNumber* stagenumber = nullptr;
	CVector3 get = CVector3::Zero;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
};

