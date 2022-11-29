#include "Boss2.h"
#include"B2Attack.h"
#include"B2Idle.h"
Boss2::Boss2()
{
	m_nextState = IB2State::SNULL;
	m_idleState = new B2Idle(this);
	m_attackState = new B2Attack(this);
	m_currentState = m_idleState;
	m_BossFire = new BossWeapon2();
}

Boss2::~Boss2()
{
	if (m_idleState != nullptr) {
		delete m_idleState;
	}
	if (m_attackState != nullptr) {
		delete m_attackState;
	}
	m_currentState = nullptr;

}

void Boss2::changeNextState(IB2State::STATE nextState)
{
	m_nextState = nextState;
}

void Boss2::Init(CollisionManager& collisionManager)
{
	m_attackState->Init();
	m_idleState->Init();

	m_HitBox = new HitBox(sf::Vector2i(200, 160));
	m_HitBox->setPosition(3500, groundY - (m_HitBox->getSize().y) / 2 - 150);
	m_HitBox->Init(sf::Vector2f(0, 0));
	m_HitBox->SetTag(BOSS2);

	collisionManager.addObj(m_HitBox);
	m_BossFire->Init(collisionManager);
}

void Boss2::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime);
	m_BossFire->Update(deltaTime);

}

void Boss2::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	m_BossFire->Render(window);

}

HitBox* Boss2::getHitBox()
{
	return m_HitBox;
}
BossWeapon2* Boss2::getWeapon()
{
	return m_BossFire;
}


void Boss2::performStateChange()
{
	if (m_nextState != IB2State::SNULL) {
		switch (m_nextState)
		{
		case IB2State::IDLE:
			m_currentState = m_idleState;
			break;
		case IB2State::ATTACK:
			m_currentState = m_attackState;
			break;
		default:
			break;
		}
		m_nextState = IB2State::SNULL;
		m_currentState->Reset();
	}
}