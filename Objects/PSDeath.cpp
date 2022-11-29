#include "PSDeath.h"

PSDeath::PSDeath(IPlayer* player)
{
	m_Player = player;
	m_timeRemain = 1.f;
}

void PSDeath::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Player/death"), sf::Vector2i(12, 1), 0.1f);
	m_Animation->setScale(0.9, 0.9);
	m_Animation->setModeEndFrame(true);
}

void PSDeath::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}