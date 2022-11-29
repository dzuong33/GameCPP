#include "GSettings.h"

GSettings::GSettings()
{
}

GSettings::~GSettings()
{
}

void GSettings::Exit()
{
}

void GSettings::Pause()
{
}

void GSettings::Resume()
{
}

void GSettings::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("X");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);
	//turn on music
	button = new GameButton();
	button->Init("MusicOn");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 8, screenHeight/2 - screenHeight / 11);
	button->setOnClick([]() {DATA->setAllowSound(true); });
	m_ListBtn.push_back(button);

	//turn off music
	button = new GameButton();
	button->Init("MusicOff");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 8, screenHeight/2 - screenHeight / 11);
	button->setOnClick([]() {DATA->setAllowSound(false); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("BG Layers/BG");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("SETTINGS");
	m_Title.setFont(*DATA->getFont("phont"));
	m_Title.setScale(3.0, 3.0);
	m_Title.setFillColor(sf::Color::Black);
	m_Title.setPosition(screenWidth / 2 - screenWidth / 6, screenHeight / 7);
}

void GSettings::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSettings::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_ListBtn) 
	{
		btn->Render(window);
	}
}