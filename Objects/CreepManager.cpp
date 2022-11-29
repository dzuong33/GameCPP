#include "CreepManager.h"

CreepManager::CreepManager()
{
    m_CreepNum = 10;
    m_TimeSpawnCreep = 2.f;
    m_currentTime = 0.f;
    // rand() % (max � min + 1) + min
}

CreepManager::~CreepManager()
{
    for (auto it : m_ListCrZombie)
    {
        if (it != nullptr)
        {
            delete it;
        }
    }
    m_ListCrZombie.clear();

    for (auto it : m_ListCrFly)
    {
        if (it != nullptr)
        {
            delete it;
        }
    }
    m_ListCrFly.clear();
}

void CreepManager::Init(CollisionManager &collisionManager)
{

    for (int i = 0; i < m_CreepNum; i++)
    {
        

        CRFly *creepF = new CRFly();
        creepF->Init();
        creepF->getHitBox()->setAlive(false);
        m_ListCrFly.push_back(creepF);
        collisionManager.addObj(creepF->getHitBox());
    }
}

void CreepManager::Update(float deltaTime)
{
    m_currentTime += deltaTime;
    if (m_currentTime > m_TimeSpawnCreep)
    {
        SpawnFly();
        m_currentTime = 0.f;
    }
    for (auto creep : m_ListCrZombie)
    {
        creep->Update(deltaTime);
    }
    for (auto creep : m_ListCrFly)
    {
        creep->Update(deltaTime);
    }
}

void CreepManager::Render(sf::RenderWindow *window)
{
    for (auto creep : m_ListCrFly)
    {
        creep->Render(window);
    }
}


void CreepManager::SpawnFly()
{
    Creep *creep = nullptr;
    for (auto it : m_ListCrFly)
    {
        if (it->getHitBox()->isAlive() == false && it->isStop() == true)
        {
            creep = it;
            break;
        }
    }
    if (creep == nullptr)
        return;
    creep->getHitBox()->setAlive(true);
    creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (150 - 50 + 1) + 50, groundY-(rand()%(250 - 10 + 1) + 10)));
    creep->Reset();
}