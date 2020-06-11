#pragma once
#include "GameNode.h"

class Image;
class MissileManager;
class Enemy : public GameNode
{
protected:
	Image* image;
	int currFrameX, currFrameY;
	int updateCount;

	int size;
	float angle;
	float speed;

	int fireDelay;
	int fireCount;

	MissileManager* missileMgr;

public:
	virtual HRESULT Init();
	virtual HRESULT Init(float posX, float posY);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	//void SetTarget(Tank* tank);
	//FPOINT GetPos() { return pos; }

	Enemy();
	virtual ~Enemy();
};

