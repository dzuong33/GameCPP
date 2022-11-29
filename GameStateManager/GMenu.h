#pragma once
#include "GameStateBase.h"
#include"../Objects/GameButton.h"
class GSMenu : public GameStateBase {
public:
	GSMenu();
	virtual ~GSMenu();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<GameButton*> m_ListBtn;
	sf::Sprite m_Background;
	sf::RectangleShape shape;
	sf::Text m_Title;
};