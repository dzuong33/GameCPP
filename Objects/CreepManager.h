#pragma once
#include "../GameManager/ResourceManager.h"
#include "CRZombie.h"
#include"CRFly.h"
#include "CollisionManager.h"

class CreepManager {
public:
	CreepManager();
	~CreepManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	void SpawnFly();
	std::list<CRZombie*> m_ListCrZombie;
	std::list<CRFly*> m_ListCrFly;
	int m_CreepNum;
	float m_TimeSpawnCreep;
	float m_currentTime;
};