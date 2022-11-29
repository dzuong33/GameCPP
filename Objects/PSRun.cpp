#include "PSRun.h"

PSRun::PSRun(IPlayer* player)
{
    m_Player = player;
}

void PSRun::Init()
{
    m_Animation = new Animation(*DATA->getTexture("Player/run"), sf::Vector2i(8, 1), 0.1f);
    m_Animation->setScale(0.9, 0.9);
}

void PSRun::Update(float deltaTime)
{
    m_Animation->Update(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_Player->changeNextState(JUMP);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
    }

    if (!m_Player->getHitBox()->isAlive())
        m_Player->changeNextState(IPState::DEATH);

    m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRun::Render(sf::RenderWindow* window)
{
    window->draw(*m_Animation);
}

void PSRun::Reset()
{
    m_Animation->Reset();
}