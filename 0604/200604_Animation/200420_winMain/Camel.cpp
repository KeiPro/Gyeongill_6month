#include "Camel.h"
#include "Animation.h"
#include "Image.h"
#include "MissileManager.h"


HRESULT Camel::Init()
{
	Enemy::Init();        

	image = ImageManager::GetSingleton()->AddImage("Camel", "Image/Camel2.bmp", pos.x, pos.y, 300, 267, 4, 3, true, RGB(255, 0, 255));

	// 0 ~ 마지막 프레임 까지 순차적으로 진행
	ani = new Animation();
	ani->Init(image->GetWidth(), image->GetHeight(), image->GetFrameWidth(), image->GetFrameHeight());
	ani->SetUpdateTime(FPS / 3.0f);
	ani->SetPlayFrame(true, true);

	// 시작 프레임과 끝 프레임을 임의로 지정 4~8까지 애니메이션을 돌린다.
	ani2 = new Animation();
	ani2->Init(image->GetWidth(), image->GetHeight(), image->GetFrameWidth(), image->GetFrameHeight());
	ani2->SetUpdateTime(FPS / 10.0f);
	ani2->SetPlayFrame(8, 3, true, true);

	// 배열 형태로 순차적인 진행이 아니게 설정
	int arrAni[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };


	ani3 = new Animation();
	ani3->Init(image->GetWidth(), image->GetHeight(), image->GetFrameWidth(), image->GetFrameHeight());
	ani3->SetUpdateTime(FPS / 15.0f);
	ani3->SetPlayFrame(arrAni, 12, true, true);

	playAni = ani3;

	return S_OK;
}

void Camel::Release()
{
	SAFE_DELETE(ani);
	SAFE_DELETE(ani2);
	SAFE_DELETE(ani3);

	Enemy::Release();
}

void Camel::Update()
{
	if (missileMgr)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_SPACE))
		{
			TimeManager::GetSingleton()->SetIsTestStart(true);
			missileMgr->Fire();
		}
	}

	if (playAni)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('1'))
		{
			playAni->Start();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('Q'))
		{
			playAni->Stop();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('A'))
		{
			playAni->Pause();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('Z'))
		{
			playAni->Resume();
		}
	}
	


	if (playAni)
	{
		playAni->UpdateKeyFrame(TimeManager::GetSingleton()->GetDeltaTime());
	}
}

void Camel::Render(HDC hdc)
{
	//Enemy::Render(hdc);

	if (missileMgr)
	{
		missileMgr->Render(hdc);
	}


	if (image)
	{
		image->AnimationRender(hdc, pos.x, pos.y, playAni);
	}
}

Camel::Camel()
{
}

Camel::~Camel()
{
}
