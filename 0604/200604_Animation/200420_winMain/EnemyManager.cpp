#include "EnemyManager.h"
#include "Enemy.h"


HRESULT EnemyManager::Init()
{
	//for (int i = 0; i < 10; i++)
	//{
	//	enemy[i].Init(80 + (i % 5) * 100, 120 + (i / 5) * 80);
	//}

	vecEnemys.resize(2);
	//vecEnemys.reserve(10);

	for (int i = 0; i < 2; i++)
	{
		// 1) resize 사용 시
		vecEnemys[i] = new Enemy();
		//vecEnemys[i]->Init(110 + (i % 5) * 100, 120 + (i / 5) * 80);

		// 2) reserve 사용 시
		//Enemy* enemy = new Enemy();
		//enemy->Init(80 + (i % 5) * 100, 120 + (i / 5) * 80);

		//vecEnemys.push_back(enemy);
	}
	vecEnemys[0]->Init(WINSIZE_X / 2, 100);
	vecEnemys[1]->Init(WINSIZE_X / 2, 500);

	return S_OK;
}

void EnemyManager::Release()
{
	for (itEnemys = vecEnemys.begin(); itEnemys != vecEnemys.end(); itEnemys++)
	{
		(*itEnemys)->Release();
		SAFE_DELETE((*itEnemys));
	}
	vecEnemys.clear();
}

void EnemyManager::Update()
{
	for (itEnemys = vecEnemys.begin(); itEnemys != vecEnemys.end(); itEnemys++)
	{
		(*itEnemys)->Update();
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (itEnemys = vecEnemys.begin(); itEnemys != vecEnemys.end(); itEnemys++)
	{
		(*itEnemys)->Render(hdc);
	}
}

void EnemyManager::AddEnemy(float posX, float posY)
{
	Enemy* enemy = new Enemy();
	enemy->Init(posX, posY);

	vecEnemys.push_back(enemy);
}

EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}
