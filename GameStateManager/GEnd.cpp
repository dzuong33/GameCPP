#include "GEnd.h"

GEnd::GEnd()
{
}

GEnd::~GEnd()
{
}

void GEnd::Exit()
{
}

void GEnd::Pause()
{
}

void GEnd::Resume()
{
}

void GEnd::Init()
{
	GameButton* button;
	// menu Button
	button = new GameButton();
	button->Init("Menu");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]()
		{
			GSM->PopState();
			GSM->PopState();
			ScoreManager::GetInstance()->UpdateHighScore();
			ScoreManager::GetInstance()->writeFile(); });
	m_ListBtn.push_back(button);

	// replay Button
	button = new GameButton();
	button->Init("Replay");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOnClick([]()
		{
			GSM->PopState();
			GSM->ChangeState(StateTypes::PLAY);
			ScoreManager::GetInstance()->UpdateHighScore();
			ScoreManager::GetInstance()->writeFile(); });
	m_ListBtn.push_back(button);

	// Background
	sf::Texture* texture = DATA->getTexture("BG Layers/BG");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	// Tile Game
	m_Title.setString("END GAME");
	m_Title.setFont(*DATA->getFont("phont"));
	m_Title.setScale(3.0, 3.0);
	m_Title.setFillColor(sf::Color::Black);
	m_Title.setPosition(screenWidth / 2 - screenWidth / 6, screenHeight / 7);

	
}

void GEnd::Update(float deltaTime)
{
	for (auto btn : m_ListBtn)
	{
		btn->Update(deltaTime);
	}
}

void GEnd::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn)
	{
		btn->Render(window);
	}
	window->draw(m_Title);
	
}