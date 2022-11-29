#include "CRFly.h"

void CRFly::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(30, 25));
	m_HitBox->Init(sf::Vector2f(300, 0));
	setStartPoint(sf::Vector2f(screenWidth, groundY - 200));
	m_HitBox->setPosition(screenWidth, groundY - 200);

	m_runAni = new Animation(*DATA->getTexture("Zombie/Enemy/Eye/Flight"), sf::Vector2i(8, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Zombie/Enemy/Eye/Death"), sf::Vector2i(4, 1), 0.1f);
	m_runAni->setScale(-1.5, 1.5);
	m_deathAni->setScale(-1.5, 1.5);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}