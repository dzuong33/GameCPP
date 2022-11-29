#include "GHighscore.h"

GHighscore::GHighscore()
{
}

GHighscore::~GHighscore()
{
	for (auto it : m_ListBtn)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
	for (auto it : m_ListScore)
	{
		if (it != nullptr)
		{
			delete it;
		}
	}
}

void GHighscore::Exit()
{
}

void GHighscore::Pause()
{
}

void GHighscore::Resume()
{
}

void GHighscore::Init()
{
	GameButton* button;
	// close Button
	button = new GameButton();
	button->Init("X");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]()
		{ GSM->PopState(); });
	m_ListBtn.push_back(button);

	// Background
	sf::Texture* texture = DATA->getTexture("BG layers/BG");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	// Tile Game
	m_Title.setString("HIGH SCORE");
	m_Title.setFont(*DATA->getFont("phont"));
	m_Title.setPosition(screenWidth / 2 - screenWidth / 6, screenHeight / 5);
	m_Title.setFillColor(sf::Color::Black);
	m_Title.setScale(2.0, 2.0);
	// ListScore
	for (int i = 0; i < ScoreManager::GetInstance()->getNum(); i++)
	{
		sf::Text* t = new sf::Text();
		t->setString(std::to_string(ScoreManager::GetInstance()->getHighScore()[i]));
		t->setFont(*DATA->getFont("phont"));
		t->setPosition(screenWidth / 2 - screenWidth / 6, screenHeight / 2 + 40 * i);
		t->setScale(2.0, 2.0);
		t->setFillColor(sf::Color::White);
		m_ListScore.push_back(t);
	}
}

void GHighscore::Update(float deltaTime)
{
	for (auto btn : m_ListBtn)
	{
		btn->Update(deltaTime);
	}
}

void GHighscore::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn)
	{
		btn->Render(window);
	}
	for (auto it : m_ListScore)
	{
		window->draw(*it);
	}
	window->draw(m_Title);
}