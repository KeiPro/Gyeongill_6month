#pragma once
#include "Enemy.h"

class Animation;
class Camel : public Enemy
{
private:
	Animation* playAni;
	Animation* ani;
	Animation* ani2;
	Animation* ani3;



public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	Camel();
	virtual ~Camel();
};

