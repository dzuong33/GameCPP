#pragma once
#include<SFML/Graphics.hpp>

class Animation :public sf::Sprite
{
protected:
	sf::Vector2i m_frameNum;
	sf::Vector2i m_currentFrame;
	float m_frameTime;
	float m_currentTime;
	sf::Vector2i m_rectXY;
	sf::Vector2i m_rectSize;
	sf::IntRect m_rect;

	bool m_modeStopAtEndFrame;
public:
	Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime);
	void CalRectSize();
	void CalRectXY();
	void applyRect();
	virtual void Update(float deltaTime);
	virtual void Reset();

	sf::Vector2i getFrameNum() { return m_frameNum; }
	sf::Vector2i getCurrentFrame() { return m_currentFrame; }
	void setModeEndFrame(bool stop);
};