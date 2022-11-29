#include "Bullet.h"

Bullet::Bullet()
{
	m_stop = true;
}

Bullet::~Bullet()
{
	m_currentAni = nullptr;
	if (m_deathAni != nullptr)
	{
		delete m_deathAni;
	}
	if (m_runAni != nullptr)
	{
		delete m_runAni;
	}
	if (m_HitBox != nullptr)
	{
		delete m_HitBox;
	}
}

void Bullet::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(52, 34));
	m_HitBox->Init(sf::Vector2f(240 * 2, 0));
	setStartPoint(sf::Vector2f(screenWidth + 100, groundY - (rand() % (200 - 10 + 1) + 10)));
	m_HitBox->setPosition(screenWidth, groundY);

	m_runAni = new AnimationBoss(*DATA->getTexture("Zombie/Boss1/Move"), sf::Vector2i(6, 1), 0.1f, 6);
	m_runAni->setScale(4.0, 4.0);
	m_deathAni = new AnimationBoss(*DATA->getTexture("Zombie/Boss1/Explosion"), sf::Vector2i(7, 1), 0.1f, 7);
	m_deathAni->setScale(4.0, 4.0);
	// m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(BOSS_Bullet);
}

void Bullet::Update(float deltaTime)
{
	if (m_stop == true)
		return;
	if (m_HitBox->isAlive())
	{
		if (m_soundIsPlaying == false) {
			DATA->playSound("Splash");
			DATA->getMusic("Splash")->setVolume(30);
			m_soundIsPlaying = true;
		}
		m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		if (m_HitBox->getPosition().x > screenWidth + 100)
		{
			m_HitBox->setPosition(m_startPoint);
			m_stop = true;
			m_HitBox->setAlive(false);
		}
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		m_currentAni = m_deathAni;
		AnimationBoss* ani = (AnimationBoss*)m_currentAni;
		if (ani->getCurrentFrameCount() != ani->getFrameTotals() - 1) 
		{
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition());
		}
		else m_stop = true;
	}
}

void Bullet::Render(sf::RenderWindow* window)
{
	if (m_stop)
		return;
	window->draw(*m_currentAni);
}

void Bullet::Reset()
{
	m_stop = false;
	m_soundIsPlaying = false;
	m_deathAni->Reset();
	m_runAni->Reset();
	m_currentAni = m_runAni;
	m_HitBox->setPosition(m_startPoint);
}