#include "CRZombie.h"

void CRZombie::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(25, 25));
	m_HitBox->Init(sf::Vector2f(240, 0));
	
	setStartPoint(sf::Vector2f(screenWidth + 100, groundY));
	m_HitBox->setPosition(screenWidth, groundY);

	m_runAni = new Animation(*DATA->getTexture("Zombie/Enemy/Skeleton/Attack"), sf::Vector2i(8, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Zombie/Enemy/Skeleton/Death"), sf::Vector2i(4, 1), 0.1f);
	m_runAni->setScale(-1.1, 1.1);
	m_deathAni->setScale(-1.1, 1.1);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}