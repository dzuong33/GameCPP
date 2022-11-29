#pragma once
#include "layers.h"

class ParalleiBackground
{
public:
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<Layer*> m_Background;
};