#pragma once
#include "../GameManager/ResourceManager.h"
#include "CollisionManager.h"
#include "Bullet2.h"

class BossWeapon2 {
public:
	BossWeapon2();
	~BossWeapon2();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	void Fire(sf::Vector2f startPoint);
private:
	std::list<Bullet2*> m_ListBullet;
	int m_Num;
	float m_currentTime;
};