#pragma once
class Player;
class GameCameraPl;
class CircleCharge;
class StageNumber;
class Game2 : public IGameObject
{
public:
	Game2();
	~Game2();
	bool Start();
	void Update();
	//ƒŒƒxƒ‹
	CLevel m_level;
	Player* m_player = nullptr;
	GameCameraPl* m_gameCameraPl = nullptr;
	CircleCharge* m_circleCharge = nullptr;
	StageNumber* stagenumber = nullptr;

	prefab::CDirectionLight* m_directionLig = nullptr;

};

