#pragma once
#include "IBoss.h"
#include "IBState.h"
#include "Hitbox.h"
class Boss : public IBoss
{
public:
	Boss();
	~Boss();
	void changeNextState(IBState::STATE nextState);

	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox();
	BossWeapon* getWeapon();

private:
	void performStateChange();
	HitBox* m_HitBox;

	IBState::STATE m_nextState;

	IBState* m_currentState;
	IBState* m_idleState;
	IBState* m_walkState;
	IBState* m_deathState;
	IBState* m_attackState; 

	BossWeapon* m_BossFire;
};