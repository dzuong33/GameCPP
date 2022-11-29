#pragma once
#include "../GameManager/ResourceManager.h"
#include "BossWeapon2.h"
class IB2State
{
public:
	enum STATE
	{
		IDLE,
		ATTACK,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};