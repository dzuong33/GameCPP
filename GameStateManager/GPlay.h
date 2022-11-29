#pragma once
#include "GameStateBase.h"
#include"../Objects/GameButton.h"
#include"../Objects/layers.h"
#include"../Objects/ParalleiBG.h"
#include"../Objects/Player.h"
#include"../Objects/CRZombie.h"
#include"../Objects/CollisionManager.h"
#include"../Objects/CreepManager.h"
#include"../Objects/Boss.h"
#include"../Objects/Boss2.h"
class GSPlay : public GameStateBase 
{
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	ParalleiBackground m_Background;
	Player m_Player;
	CollisionManager m_CollisionManager;
	CreepManager m_CreepManager;
	Boss m_Boss;
	Boss2 m_Boss2;
	float m_currentTime;
	int m_currentScore;
	sf::Text m_Score;
};