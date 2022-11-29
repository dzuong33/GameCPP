#include "GAbout.h"

GAbout::GAbout()
{
}

GAbout::~GAbout()
{
}

void GAbout::Exit()
{
}

void GAbout::Pause()
{
}

void GAbout::Resume()
{
}

void GAbout::Init()
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

	//Background
	sf::Texture* texture = DATA->getTexture("BG layers/BG");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("The Dawn Game\nDEVELOPED By: Hoang Duong\ninstruction: Run till the end\nWASD to move\nPress J to hold in the air");
	m_Title.setFont(*DATA->getFont("phont"));
	m_Title.setScale(2.0, 2.0);
	m_Title.setFillColor(sf::Color::White);
	m_Title.setPosition(screenWidth / 2 - screenWidth / 3, screenHeight / 3);
}

void GAbout::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
}