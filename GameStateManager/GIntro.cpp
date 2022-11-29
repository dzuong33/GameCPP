#include "GIntro.h"
#include "../GameStateManager/GameStateMachine.h"
GSIntro::GSIntro()
{
	m_currentTime = 0;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	sf::Texture* texture = DATA->getTexture("pro");
	m_intro.setTexture(*texture);
	m_intro.setPosition(screenWidth / 2, screenHeight / 2);
	m_intro.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_intro.setScale(0.17, 0.17);
	printf("Intro showed\n");
}

void GSIntro::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= 3.f)
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->draw(m_intro);
}
