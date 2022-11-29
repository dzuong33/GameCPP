#include "Bullet2.h"

Bullet2::Bullet2()
{
	m_stop = true;
}

Bullet2::~Bullet2()
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

void Bullet2::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(45, 28));
	m_HitBox->Init(sf::Vector2f(240*2, 0));
	setStartPoint(sf::Vector2f(screenWidth + 100, groundY));
	m_HitBox->setPosition(screenWidth, groundY);

	m_runAni = new AnimationBoss(*DATA->getTexture("Zombie/Boss2/Spark"), sf::Vector2i(5, 1), 0.1f, 5);
	m_runAni->setScale(-2.0, 2.0);
	m_deathAni = new AnimationBoss(*DATA->getTexture("Zombie/Boss2/Hit"), sf::Vector2i(7, 1), 0.1f, 7);
	m_deathAni->setScale(-2.0, 2.0);
	//m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(BOSS_Bullet2);
}

void Bullet2::Update(float deltaTime)
{
	if (m_stop == true)
		return;
	if (m_HitBox->isAlive())
	{
		if (m_soundIsPlaying == false) {
			DATA->playSound("Spray");
			DATA->getMusic("Spray")->setVolume(30);
			m_soundIsPlaying = true;
		}
		m_HitBox->move(-m_HitBox->getVelocity() * deltaTime);
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

void Bullet2::Render(sf::RenderWindow* window)
{
	if (m_stop)
		return;
	window->draw(*m_currentAni);
}

void Bullet2::Reset()
{
	m_stop = false;
	m_soundIsPlaying = false;
	m_deathAni->Reset();
	m_runAni->Reset();
	m_currentAni = m_runAni;
	m_HitBox->setPosition(m_startPoint);
}