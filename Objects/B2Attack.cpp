#include "B2Attack.h"

B2Attack::B2Attack(IBoss2* boss)
{
	m_Boss = boss;
}

void B2Attack::Init()
{
	m_Animation = new AnimationBoss(*DATA->getTexture("Zombie/Boss2/demon-attack"), sf::Vector2i(11, 1), 0.1f, 11);
	m_Animation->setScale(1.2, 1.2);
	m_ChangeTime = 3.f;
	m_currentTime = 0.f;
}

void B2Attack::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	AnimationBoss* ani = (AnimationBoss*)m_Animation;

	//printf("%d\n", ani->getCurrentFrameCount());
	if (ani->getCurrentFrameCount() == ani->getFrameTotals() - 1)
	{
		sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
		pos.y += 60;
		m_Boss->getWeapon()->Fire(pos);
		m_Boss->changeNextState(STATE::IDLE);
	}
	
	sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
	m_Animation->setPosition(pos);
}

void B2Attack::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void B2Attack::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}