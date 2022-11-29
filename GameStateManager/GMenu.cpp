#include "../GameStateManager/GMenu.h"
#include "../GameConfigs.h"
#include"GIntro.h"
#include"GSettings.h"
GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	printf("Menu showed");
	GameButton* button;
	//PlayButton
	button = new GameButton();
	button->Init("Play");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::PLAY); });
	button->setPosition(screenWidth / 2, screenHeight / 2);
	button->setSize(sf::Vector2f(120, 120));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("X");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 6, screenHeight - screenHeight / 8);
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	m_ListBtn.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("Setting");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 6, screenHeight - screenHeight / 8);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SETTING); });
	m_ListBtn.push_back(button);

	//HighScore Button
	button = new GameButton();
	button->Init("HighScore");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 , screenHeight - screenHeight / 8);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::HIGHSCORE); });
	m_ListBtn.push_back(button);

	//Game Name
	m_Title.setString("The Dawn");
	m_Title.setFont(*DATA->getFont("phont"));
	m_Title.setScale(3.0, 3.0);
	m_Title.setFillColor(sf::Color::Black);
	m_Title.setPosition(screenWidth / 2 - screenWidth / 6, screenHeight / 7);

	//Background
	sf::Texture* texture = DATA->getTexture("BG Layers/BG");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//about Button
	button = new GameButton();
	button->Init("about");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 2 + 100, screenHeight - screenHeight / 10);
	button->setScale(0.7, 0.7);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::ABOUT); });
	m_ListBtn.push_back(button);

	//Sound
	DATA->playMusic("BackSound");
	DATA->getMusic("BackSound")->setLoop(true);;
	DATA->getMusic("BackSound")->setVolume(30);
}

void GSMenu::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
}