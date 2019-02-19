#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"

class Player;
class GameCameraPl;
class Stage;
class DemoCircle;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	Player* m_player = nullptr;
	GameCameraPl* m_gameCameraPl = nullptr;
	Stage* m_stage = nullptr;
	DemoCircle* m_demoCircle = nullptr;
	CQuaternion m_rotation = CQuaternion::Identity;
};

