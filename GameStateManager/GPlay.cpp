#include "GPlay.h"

GSPlay::GSPlay()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	printf("Play game");
	m_Background.Init();
	m_Player.Init();
	m_Boss.Init(m_CollisionManager);
	m_Boss2.Init(m_CollisionManager);
	m_CollisionManager.addObj(m_Player.getHitBox());
	m_CreepManager.Init(m_CollisionManager);

	m_Score.setFont(*DATA->getFont("phont"));
	m_Score.setString("0");
	m_Score.setFillColor(sf::Color::Black);
	m_Score.setPosition(50, 50);
	m_Score.setScale(2.0, 2.0);

	DATA->playMusic("BackSound");
	DATA->getMusic("BackSound")->setLoop(true);;
	DATA->getMusic("BackSound")->setVolume(30);
}

void GSPlay::Update(float deltaTime)
{
	if (m_Player.getHitBox()->isAlive()) {
		m_currentTime += deltaTime;
		if (m_currentTime >= 0.5f) {
			m_currentScore++;
			m_Score.setString(std::to_string(m_currentScore));
			m_currentTime -= 0.6f;
		}
	}
	else ScoreManager::GetInstance()->setCurrentScore(m_currentScore);

	if (m_Player.getHitBox()->isAlive()) 
		m_Background.Update(deltaTime);
	m_Player.Update(deltaTime);
	if (m_Player.getHitBox()->isAlive()) 
	{
		if (m_currentScore >= 70 && m_currentScore <= 80)
		{
			m_Boss.Update(deltaTime);
			m_CollisionManager.Update();
		}
		if (m_currentScore >= 120 && m_currentScore <= 140)
		{
			m_Boss.Update(deltaTime);
			m_CreepManager.Update(deltaTime);
			m_CollisionManager.Update();
		}
		if (m_currentScore >= 200 && m_currentScore <= 240)
		{
			m_Boss.Update(deltaTime);
			m_CreepManager.Update(deltaTime);
			m_CollisionManager.Update();
		}
		if (m_currentScore >= 250 && m_currentScore <= 3280)
		{
			m_Boss.Update(deltaTime);
			m_CreepManager.Update(deltaTime);
			m_CollisionManager.Update();
		}
		if (m_currentScore > 320)
		{
			m_Boss2.Update(deltaTime);
			m_CreepManager.Update(deltaTime);
			m_CollisionManager.Update();
		}
		m_Boss2.Update(deltaTime);
		m_Boss.Update(deltaTime);
		m_CreepManager.Update(deltaTime);
		m_CollisionManager.Update();
	}
}

void GSPlay::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);
	m_Boss.Render(window);
	m_Boss2.Render(window);
	m_Player.Render(window);
	m_CreepManager.Render(window);
	window->draw(m_Score);

}