#pragma once
#include "GameStateBase.h"
class GSettings : public GameStateBase {
public:
	GSettings();
	virtual ~GSettings();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	sf::Text m_Title;
	std::list<GameButton*> m_ListBtn;

};