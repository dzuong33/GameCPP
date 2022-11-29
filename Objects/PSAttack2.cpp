#include "PSAttack2.h"

PSAttack2::PSAttack2(IPlayer* player)
{
	m_Player = player;
}

void PSAttack2::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Player/attack2"), sf::Vector2i(11, 1), 0.1f);
	m_Animation->setScale(0.9, 0.9);
}

void PSAttack2::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Player->changeNextState(JUMP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Player->changeNextState(FALL);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Player->changeNextState(FALL);
	}

	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::DEATH);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSAttack2::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}
void PSAttack2::Reset()
{
	m_Animation->Reset();
}
