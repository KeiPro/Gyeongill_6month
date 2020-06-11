#include "Missile.h"
#include "macroFunction.h"
#include "Enemy.h"
#include "Image.h"

HRESULT Missile::Init()
{
	pos.x = 0;
	pos.y = 0;
	size = 21;
	angle = PI / 2.0f;
	speed = 400.0f;
	isFire = false;
	adjustAngle = 0.0f;

	target = nullptr;

	img = new Image();
	if (FAILED(img->Init("Image/bullet.bmp", size, size, true, RGB(255, 0, 255))))
	{
		MessageBox(g_hWnd, "Image/bullet.bmp 초기화 실패", "Missile.cpp", MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

void Missile::Release()
{
	img->Release();
	delete img;
}

void Missile::Update()
{
	/*
		x * x + y * y = h * h;
		(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) = h * h;
	*/

	if (isFire)
	{
		if (target)
		{
			float x = target->GetPos().x - pos.x;
			float y = target->GetPos().y - pos.y;

			float targetAngle = atan2(-y, x);
			//static float adjust = 0.0f;
			//adjust = (adjust + 2.0f < 100.0f) ? adjust + 2.0f : 99.9f;
			adjustAngle += 2.0f;
			if (adjustAngle >= 100.0f)
			{
				adjustAngle = 98.0f;
			}
			angle += (targetAngle - angle) / (100.0f - adjustAngle);
		}

		pos.x += speed * cosf(angle) * TimeManager::GetSingleton()->GetDeltaTime();
		pos.y -= speed * sinf(angle) * TimeManager::GetSingleton()->GetDeltaTime();

		if (pos.y >= 500.0f)
		{
			TimeManager::GetSingleton()->SetIsTestStart(false);
		}


		//// 이동 후에 벽 충돌이 일어났는지 확인
		//// 왼쪽 벽
		//if (pos.x - (size / 2) <= 0)
		//{
		//	angle = PI - angle;
		//}
		//// 오른쪽 벽
		//else if (pos.x + (size / 2) >= WINSIZE_X)
		//{
		//	angle = PI - angle;
		//}
		//// 위쪽 벽
		//if (pos.y - (size / 2) <= 0)
		//{
		//	angle = PI * 2 - angle;
		//}
		//// 아래쪽 벽
		//else if (pos.y + (size / 2) >= WINSIZE_Y)
		//{
		//	angle = PI * 2 - angle;
		//}
	}
}

void Missile::Render(HDC hdc)
{
	if (isFire)
	{
		if (img)
		{
			img->Render(hdc, pos.x, pos.y);
		}

		//RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
	}
}

Missile::Missile()
{
}


Missile::~Missile()
{
}
