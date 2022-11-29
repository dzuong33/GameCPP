#pragma once
#include "IB2State.h"
#include"Hitbox.h"
#include"../Objects/CollisionManager.h"
class IBoss2
{
public:
	virtual void changeNextState(IB2State::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	virtual BossWeapon2* getWeapon() = 0;
};