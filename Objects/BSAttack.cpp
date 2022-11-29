#include "BSAttack.h"

BSAttack::BSAttack(IBoss* boss)
{
	m_Boss = boss;
}

void BSAttack::Init()
{
	m_Animation = new AnimationBoss(*DATA->getTexture("Zombie/Boss1/Attack"), sf::Vector2i(15, 1), 0.1f, 15);
	m_ChangeTime = 1.7;
	m_currentTime = 0.f;
}

void BSAttack::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	AnimationBoss* ani = (AnimationBoss*)m_Animation;

	printf("%d\n", ani->getCurrentFrameCount());
	if (ani->getCurrentFrameCount() == ani->getFrameTotals() - 1)
	{
		sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
		pos.y += 60;
		m_Boss->getWeapon()->Fire(pos);
		m_Boss->changeNextState(STATE::WALK);
	}
	if (m_Boss->getHitBox()->getPosition().x > 80)
	{
		m_Boss->getHitBox()->move(-100 * deltaTime, 0);
	}

	sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
	pos.y += -27;
	pos.x += 50;
	m_Animation->setPosition(pos);
}

void BSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSAttack::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}