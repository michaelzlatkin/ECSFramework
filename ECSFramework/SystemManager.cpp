#include "SystemManager.h"
#include <iostream>
#include <exception>

SystemManager::~SystemManager()
{
	for (int i = 0; i < MAX_SYSTEMS; i++)
	{
		delete mSystems[i];
		mSystems[i] = nullptr;
	}
}

void SystemManager::AddSystem(ISystem* system)
{
	try
	{
		if (mIndex < MAX_SYSTEMS)
		{
			mSystems[mIndex] = system;
			mSystems[mIndex]->SetIsActive(true);
			mIndex++;
		}
		else
		{
			throw std::exception("Reached the system limit!");
		}
	}
	catch (std::exception e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
}

void SystemManager::UpdateSystems(const float &deltaTime, const unsigned int &entityIndex)
{
	for (int i = 0; i < mIndex; i++)
	{
		if (mSystems[i] && mSystems[i]->GetIsActive())
		{
			mSystems[i]->Update(deltaTime, entityIndex);
		}
		else break;
	}
}