#include "PSRoll.h"

PSRoll::PSRoll(IPlayer* player)
{
	m_Player = player;
	m_currentTime = 0.f;
}

void PSRoll::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Player/roll"), sf::Vector2i(7, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
	m_Animation->setScale(0.9, 0.9);
}

void PSRoll::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;

	float v = 10 * m_currentTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime*1.5, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime*1.5, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Player->changeNextState(RUN);
	}
	if (!m_Player->getHitBox()->isAlive())
		m_Player->changeNextState(IPState::RUN);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRoll::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}
void PSRoll::Reset()
{
	m_Animation->Reset();
}
