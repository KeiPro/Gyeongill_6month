#include "pch.h"
#include "macroFunction.h"
#include "Enemy.h"
#include "Tank.h"
#include "Image.h"
#include "MissileManager.h"

HRESULT Enemy::Init()
{
	pos.x = WINSIZE_X / 2;
	pos.y = 120;

	ImageManager::GetSingleton()->AddImage("UFO", "Image/ufo.bmp", pos.x, pos.y, 530, 32, 10, 1, true, RGB(255, 0, 255));
	image = ImageManager::GetSingleton()->FindImage("UFO");

	//image = new Image();
	//image->Init("Image/ufo.bmp", pos.x, pos.y, 530, 32, 10, 1, true, RGB(255, 0, 255));
	currFrameX = currFrameY = 0;
	updateCount = 0;

	speed = 1.0f;
	angle = PI;
	size = 40;

	fireDelay = rand() % 200 + 300;
	fireCount = 0;

	missileMgr = new MissileManager();
	missileMgr->Init();
	missileMgr->SetOwner(this);

	return S_OK;
}

HRESULT Enemy::Init(float posX, float posY)
{
	pos.x = posX;
	pos.y = posY;

	ImageManager::GetSingleton()->AddImage("UFO", "Image/ufo.bmp", pos.x, pos.y, 530, 32, 10, 1, true, RGB(255, 0, 255));
	image = ImageManager::GetSingleton()->FindImage("UFO");

	//image = new Image();
	//image->Init("Image/ufo.bmp", pos.x, pos.y, 530, 32, 10, 1, true, RGB(255, 0, 255));
	currFrameX = currFrameY = 0;
	updateCount = 0;

	speed = 1.0f;
	angle = PI;
	size = 40;

	fireDelay = rand() % 200 + 300;
	fireCount = 0;

	missileMgr = new MissileManager();
	missileMgr->Init();
	missileMgr->SetOwner(this);

	return S_OK;
}

void Enemy::Release()
{
	missileMgr->Release();
	SAFE_DELETE(missileMgr);

	//image->Release();
	//SAFE_DELETE(image);
}

void Enemy::Update()
{
	//pos.x += cosf(angle) * speed;
	//pos.y -= sinf(angle) * speed;
	updateCount++;
	if (updateCount % 5 == 0)
	{
		currFrameX++;
		if (currFrameX > image->GetMaxKeyFrameX())
		{
			currFrameX = 0;
		}
		updateCount = 0;
	}

	if (missileMgr)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_SPACE))
		{
			TimeManager::GetSingleton()->SetIsTestStart(true);
			missileMgr->Fire();
		}

		//fireCount++;
		//if (fireCount > fireDelay)
		//{
		//	if (missileMgr->Fire())
		//	{
		//		fireCount = 0;
		//		fireDelay = rand() % 200 + 300;
		//	}
		//}

		missileMgr->Update();
	}
}

void Enemy::Render(HDC hdc)
{
	if (missileMgr)
	{
		missileMgr->Render(hdc);
	}

	if (image)
	{
		image->FrameRender(hdc, pos.x, pos.y, currFrameX, currFrameY);
	}

	//RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
}

//void Enemy::SetTarget(Tank * tank)
//{
//	target = tank;
//	float x = (float)(target->GetCenter().x) - pos.x;
//	float y = (float)(target->GetCenter().y) - pos.y;
//
//	angle = atan2(-y, x);
//}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
