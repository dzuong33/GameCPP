#include "BossWeapon2.h"

BossWeapon2::BossWeapon2()
{
	m_Num = 10;
	m_currentTime = 0.f;
	//rand() % (max � min + 1) + min
}

BossWeapon2::~BossWeapon2()
{
	for (auto it : m_ListBullet) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListBullet.clear();
}

void BossWeapon2::Init(CollisionManager& collisionManager)
{

	for (int i = 0; i < m_Num; i++)
	{
		Bullet2* bullet = new Bullet2();
		bullet->Init();
		bullet->getHitBox()->setAlive(false);
		m_ListBullet.push_back(bullet);
		collisionManager.addObj(bullet->getHitBox());

	}
}

void BossWeapon2::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	for (auto creep : m_ListBullet) {
		creep->Update(deltaTime);
	}
}

void BossWeapon2::Render(sf::RenderWindow* window)
{
	for (auto creep : m_ListBullet) {
		creep->Render(window);
	}
}

void BossWeapon2::Fire(sf::Vector2f startPoint)
{
	Bullet2* bullet = nullptr;
	for (auto it : m_ListBullet) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			bullet = it;
			break;
		}
	}
	if (bullet == nullptr) return;
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}