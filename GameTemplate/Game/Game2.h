#pragma once
class Player;
class GameCameraPl;

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
	prefab::CDirectionLight* m_directionLig = nullptr;
};

