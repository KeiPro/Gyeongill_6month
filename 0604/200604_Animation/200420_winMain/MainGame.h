#pragma once
#include "GameNode.h"

class Camel;
class SpaceShip;
class KofPlayer;
class Tank;
class Missile;
class Enemy;
class EnemyManager;
class Image;
class MainGame : public GameNode
{
private:
	HDC hdc;
	bool isInit;
	HANDLE hTimer;

	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;

	SpaceShip* spaceShip;

	Camel* camel;

	//Enemy* enemy;
	EnemyManager* enemyMgr;


	Image* bg;
	Image* backBuffer;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	LRESULT MainProc(HWND hWnd, UINT iMessage,
		WPARAM wParam, LPARAM lParam);

	float GetAngle(float x1, float y1, float x2, float y2);
	float GetDistance(float x1, float y1, float x2, float y2);
	bool CheckCollision(Missile* m1, Missile* m2);

	MainGame();
	~MainGame();
};

