#include "PSAttack1.h"

PSAttack::PSAttack(IPlayer* player)
{
	m_Player = player;
}

void PSAttack::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Player/fall"), sf::Vector2i(3, 1), 0.1f);
	m_Animation->setScale(0.9, 0.9);
}

void PSAttack::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
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

void PSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}
void PSAttack::Reset()
{
	m_Animation->Reset();
}
