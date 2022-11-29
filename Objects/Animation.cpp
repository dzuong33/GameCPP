#include "Animation.h"

Animation::Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime)
{
	m_frameNum = frameNum;
	m_frameTime = frameTime;
	this->setTexture(texture);
	m_currentFrame = sf::Vector2i(0, 0);
	m_currentTime = 0.f;
	CalRectSize();
	CalRectXY();
	applyRect();
	this->setOrigin((sf::Vector2f)m_rectSize / 2.f);
	this->setScale(1.2, 1.2);
	m_modeStopAtEndFrame = false;
}

void Animation::CalRectSize()
{
	m_rectSize = sf::Vector2i(this->getTexture()->getSize().x / m_frameNum.x, this->getTexture()->getSize().y / m_frameNum.y);
}

void Animation::CalRectXY()
{
	m_rectXY.x = m_currentFrame.x * m_rectSize.x;
	m_rectXY.y = m_currentFrame.y * m_rectSize.y;
}

void Animation::applyRect()
{
	m_rect = sf::IntRect(m_rectXY, m_rectSize);
	this->setTextureRect(m_rect);
}

void Animation::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_frameTime)
	{
		m_currentFrame.x++;
		if (m_currentFrame.x == m_frameNum.x)
		{
			m_currentFrame.x = 0;
		}
		CalRectXY();
		applyRect();
		m_currentTime -= m_frameTime;
	}
}
void Animation::Reset()
{
	m_currentFrame.x = 0;
	m_currentTime = 0.f;
}
void Animation::setModeEndFrame(bool stop)
{
	m_modeStopAtEndFrame = stop;
}