#pragma once
#include "IBoss2.h"
#include "IB2State.h"
#include "Hitbox.h"
class Boss2 : public IBoss2
{
public:
	Boss2();
	~Boss2();
	void changeNextState(IB2State::STATE nextState);

	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox();
	BossWeapon2* getWeapon();


private:
	void performStateChange();
	HitBox* m_HitBox;

	IB2State::STATE m_nextState;

	IB2State* m_currentState;
	IB2State* m_idleState;
	IB2State* m_attackState;

	BossWeapon2* m_BossFire;

};