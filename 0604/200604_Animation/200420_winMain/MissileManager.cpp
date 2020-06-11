#include "MissileManager.h"
#include "Missile.h"


HRESULT MissileManager::Init()
{
	//vecMissiles.reserve(10);
	//for (int i = 0; i < 10; i++)
	//{
	//	Missile* missile = new Missile();
	//	missile->Init();
	//	vecMissiles.push_back(missile);
	//}

	vecMissiles.resize(10);
	for (int i = 0; i < vecMissiles.size(); i++)
	{
		vecMissiles[i] = new Missile();
		vecMissiles[i]->Init();
	}

	owner = nullptr;

	return S_OK;
}

void MissileManager::Release()
{
	for (auto& it : vecMissiles)
	{
		it->Release();
		SAFE_DELETE(it);
	}
	vecMissiles.clear();
}

void MissileManager::Update()
{
	for (auto& it : vecMissiles)
	{
		it->Update();
	}
}

void MissileManager::Render(HDC hdc)
{
	for (auto& it : vecMissiles)
	{
		it->Render(hdc);
	}
}

bool MissileManager::Fire()
{
	for (auto& it : vecMissiles)
	{
		if (it->GetIsFire())
		{
			continue;
		}

		it->SetIsFire(true);
		it->SetAngle(DEGREE_TO_RADIAN(270));
		it->SetPos(owner->GetPos());
		return true;
	}

	return false;
}

MissileManager::MissileManager()
{
}


MissileManager::~MissileManager()
{
}
