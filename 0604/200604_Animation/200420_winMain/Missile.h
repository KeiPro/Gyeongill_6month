#pragma once
#include "pch.h"
#include "GameNode.h"

class Enemy;
class Image;
class Missile : public GameNode
{
private:
	FPOINT pos;
	int size;
	float angle;
	float speed;
	bool isFire;
	float adjustAngle;

	Enemy* target;
	Image* img;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetTarget(Enemy* enemy) { target = enemy; }
	void SetPos(FPOINT pt) { pos = pt; }
	FPOINT GetPos() { return pos; }
	void SetIsFire(bool b) { isFire = b; }
	bool GetIsFire() { return isFire; }
	void SetAngle(float angle) { this->angle = angle; }
	float GetSize() { return size; }
	void SetSpeed(float _speed) { speed = _speed; }

	Missile();
	~Missile();
};

