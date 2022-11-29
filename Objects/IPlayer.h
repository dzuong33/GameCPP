#pragma once
#include "IPState.h"
#include"Hitbox.h"
class IPlayer
{
public:
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
};