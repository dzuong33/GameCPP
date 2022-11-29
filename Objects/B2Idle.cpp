#include "B2Idle.h"

B2Idle::B2Idle(IBoss2* boss)
{
	m_Boss = boss;
}

void B2Idle::Init()
{
	m_Animation = new AnimationBoss(*DATA->getTexture("Zombie/Boss2/Idle"), sf::Vector2i(6, 1), 0.1f, 6);
	m_Animation->setScale(1.2, 1.2);
	m_ChangeTime = 3.f;
	m_currentTime = 0.f;
}

void B2Idle::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	AnimationBoss* ani = (AnimationBoss*)m_Animation;
	if (m_currentTime > m_ChangeTime)
	{
		int luckyState = rand() % 2;
		switch (luckyState)
		{
		case 0:
			m_Boss->changeNextState(STATE::ATTACK);
			break;
		default:
			break;
		}
	}
	if (m_Boss->getHitBox()->getPosition().x > 900)
	{
		m_Boss->getHitBox()->move(-150 * deltaTime, 0);
	}
	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
}

void B2Idle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void B2Idle::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}