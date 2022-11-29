#pragma once
#include "../GameManager/ResourceManager.h"

class IPState 
{
public:
	enum STATE
	{
		IDLE,
		RUN,
		JUMP,
		FALL,
		DEATH,
		ATTACK,
		ATTACK2,
		ROLL,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};