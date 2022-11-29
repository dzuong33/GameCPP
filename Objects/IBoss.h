#pragma once
#include "IBState.h"
#include "Hitbox.h"
#include "../Objects/CollisionManager.h"
class IBoss
{
public:
	virtual void changeNextState(IBState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	virtual BossWeapon* getWeapon() = 0;
};