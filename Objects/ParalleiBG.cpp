#include "paralleiBG.h"

void ParalleiBackground::Init()
{
	Layer* layer;
	std::string path = "BG Layers/";
	//Layer 2
	layer = new Layer();
	layer->Init(path + "10",0);
	m_Background.push_back(layer);
	//Layer 3
	layer = new Layer();
	layer->Init(path + "7", 60);
	m_Background.push_back(layer);
	//Layer 4
	layer = new Layer();
	layer->Init(path + "6", 100);
	m_Background.push_back(layer);
	//Layer 5
	layer = new Layer();
	layer->Init(path + "5", 110);
	m_Background.push_back(layer);
	//Layer 6
	layer = new Layer();
	layer->Init(path + "12", 120);
	m_Background.push_back(layer);
	//Layer 7
	layer = new Layer();
	layer->Init(path + "13", 140);
	m_Background.push_back(layer);
	//Layer 8
	layer = new Layer();
	layer->Init(path + "11", 170);
	m_Background.push_back(layer);
	//Layer 9
	layer = new Layer();
	layer->Init(path + "14", 200);
	m_Background.push_back(layer);
}

void ParalleiBackground::Update(float deltaTime)
{
	for (auto layer : m_Background) {
		layer->Update(deltaTime);
	}
}

void ParalleiBackground::Render(sf::RenderWindow* window)
{
	for (auto layer : m_Background) {
		layer->Render(window);
	}
}