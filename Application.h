#pragma once
#include "GameStateManager/GameStateMachine.h"
#include "../Sources/GameManager/ResourceManager.h"
#include "GameConfigs.h"
class Application {
public:
	void Run();
	~Application();
private:
	void Init();
	void Update(float deltaTime);
	void Render();
private:
	sf::RenderWindow* m_window;
};