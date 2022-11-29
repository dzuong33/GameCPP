#pragma once
#include"../GameManager/ResourceManager.h"
#include "GameStateBase.h"

class GSIntro : public GameStateBase {
public:
	GSIntro();
	virtual ~GSIntro();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	float m_currentTime;
	sf::Sprite m_intro;

};