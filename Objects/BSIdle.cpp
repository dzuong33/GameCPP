#include "BSIdle.h"

BSIdle::BSIdle(IBoss* boss)
{
	m_Boss = boss;
}

void BSIdle::Init()
{
	m_Animation = new AnimationBoss(*DATA->getTexture("Zombie/Boss1/Idle"), sf::Vector2i(6, 1), 0.1f, 6);
	m_ChangeTime = 1.f;
	m_currentTime = 0.f;
}

void BSIdle::Update(float deltaTime)
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
		case 1:
			m_Boss->changeNextState(STATE::WALK);
			break;
		default:
			break;
		}
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
}

void BSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSIdle::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}