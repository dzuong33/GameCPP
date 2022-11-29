#include "GameStateBase.h"
#include"GMenu.h"
#include"GIntro.h"
#include"GPlay.h"
#include"GSettings.h"
#include"GEnd.h"
#include"GHighscore.h"
#include"GAbout.h"
void GameStateBase::Update(float deltaTime)
{
}
GameStateBase* GameStateBase::CreateState(StateTypes st) {
	GameStateBase* gs = nullptr;
	switch (st)
	{
	case INVALID:
		break;
	case INTRO:
		gs = new GSIntro();
		break;
	case MENU:
		gs = new GSMenu();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case SETTING:
		gs = new GSettings();
		break;
	case ABOUT:
		gs = new GAbout();
		break;
	case HIGHSCORE:
		gs = new GHighscore();
		break;
	case END:
		gs = new GEnd();
		break;
	default:
		break;
	}
	return gs;
}

GameStateBase::GameStateBase()
{
}

GameStateBase::~GameStateBase()
{
}
