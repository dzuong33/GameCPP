#pragma once
#include "Animation.h"

class AnimationBoss :public Animation {
public:
	AnimationBoss(sf::Texture& texture, sf::Vector2i frameNum, float frameTime, int frameTotals);
	void Update(float deltaTime);
	void Reset();
	int getFrameTotals() { return m_frameTotals; };
	int getCurrentFrameCount() { return m_currentFrameCount; };
private:
	int m_frameTotals;
	int m_currentFrameCount;
};