#pragma once
class Player;
class GameCameraPl;
class CircleCharge;
class StageNumber;
class PlayerHpBer;
class Kabuto;
class Tombo;
class Game2 : public IGameObject
{
public:
	Game2();
	~Game2();
	bool Start();
	void Update();
	//���x��
	CLevel m_level;
	Player* m_player = nullptr;
	GameCameraPl* m_gameCameraPl = nullptr;
	CircleCharge* m_circleCharge = nullptr;
	StageNumber* stagenumber = nullptr;
	PlayerHpBer* m_HpBer = nullptr;
	Tombo* m_tombo = nullptr;
	prefab::CDirectionLight* m_directionLig = nullptr;

};
