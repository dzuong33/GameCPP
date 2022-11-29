#pragma once
#include "../GameManager/ResourceManager.h"
#include "BossWeapon.h"
class IBState
{
public:
	enum STATE
	{
		IDLE,
		WALK,
		DEATH,
		ATTACK,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};