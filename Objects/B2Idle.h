#pragma once
#include "IB2State.h"
#include "IBoss2.h"

class B2Idle :public IB2State {
public:
	B2Idle(IBoss2* boss);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IBoss2* m_Boss;
	Animation* m_Animation;

	float m_currentTime;
	float m_ChangeTime;

};