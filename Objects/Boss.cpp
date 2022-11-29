#include "Boss.h"
#include"BSAttack.h"
#include"BSWalk.h"
#include"BSIdle.h"
Boss::Boss()
{
	m_nextState = IBState::SNULL;
	m_attackState = new BSAttack(this);
	m_walkState = new BSWalk(this);
	m_idleState = new BSIdle(this);
	m_currentState = m_walkState;
	m_BossFire = new BossWeapon();
}

Boss::~Boss()
{
	if (m_idleState != nullptr) {
		delete m_idleState;
	}
	if (m_walkState != nullptr) {
		delete m_walkState;
	}
	if (m_attackState != nullptr) {
		delete m_attackState;
	}
	if (m_BossFire != nullptr) {
		delete m_BossFire;
	}
	m_currentState = nullptr;

}

void Boss::changeNextState(IBState::STATE nextState)
{
	m_nextState = nextState;
}

void Boss::Init(CollisionManager& collisionManager)
{
	m_walkState->Init();
	m_attackState->Init();
	m_idleState->Init();

	m_HitBox = new HitBox(sf::Vector2i(150, 200));
	m_HitBox->setPosition(-1500, groundY - (m_HitBox->getSize().y) / 2 + 30);
	m_HitBox->Init(sf::Vector2f(0, 0));
	m_HitBox->SetTag(BOSS);

	collisionManager.addObj(m_HitBox);
	m_BossFire->Init(collisionManager);
}

void Boss::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime);
	m_BossFire->Update(deltaTime);

}

void Boss::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	m_BossFire->Render(window);

}

HitBox* Boss::getHitBox()
{
	return m_HitBox;
}

BossWeapon* Boss::getWeapon()
{
	return m_BossFire;
}


void Boss::performStateChange()
{
	if (m_nextState != IBState::SNULL) {
		switch (m_nextState)
		{
		case IBState::IDLE:
			m_currentState = m_idleState;
			break;
		case IBState::WALK:
			m_currentState = m_walkState;
			break;
		case IBState::ATTACK:
			m_currentState = m_attackState;
			break;
		case IBState::DEATH:
			m_currentState = m_deathState;
			break;
		default:
			break;
		}
		m_nextState = IBState::SNULL;
		m_currentState->Reset();
	}
}