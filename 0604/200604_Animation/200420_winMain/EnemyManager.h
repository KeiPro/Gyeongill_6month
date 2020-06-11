#pragma once
#include "GameNode.h"
#include <vector>

class Enemy;
class EnemyManager : public GameNode
{
private:
	vector<Enemy*>	vecEnemys;
	vector<Enemy*>::iterator	itEnemys;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void AddEnemy(float posX, float posY);

	EnemyManager();
	~EnemyManager();
};

