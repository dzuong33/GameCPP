#include "BSWalk.h"

BSWalk::BSWalk(IBoss* boss)
{
	m_Boss = boss;
}

void BSWalk::Init()
{
	m_Animation = new AnimationBoss(*DATA->getTexture("Zombie/Boss1/Walk"), sf::Vector2i(12,1), 0.1f, 12);
	m_ChangeTime = 3.f;
	m_currentTime = 0.f;
}

void BSWalk::Update(float deltaTime)
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
			m_Boss->changeNextState(STATE::IDLE);
			break;
		default:
			break;
		}
	}
	if (m_Boss->getHitBox()->getPosition().x < 200) {
		m_Boss->getHitBox()->move(150 * deltaTime, 0);
	}
	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
}

void BSWalk::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSWalk::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}