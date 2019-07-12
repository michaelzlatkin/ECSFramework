#include "SystemManager.h"
#include <iostream>
#include <exception>

SystemManager::~SystemManager()
{
	for (int i = 0; i < MAX_SYSTEMS; i++)
	{
		delete systems[i];
		systems[i] = nullptr;
	}
}

void SystemManager::AddSystem(ISystem* system)
{
	try
	{
		if (index < MAX_SYSTEMS)
		{
			systems[index] = system;
			index++;
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

void SystemManager::UpdateSystems(float deltaTime, unsigned int entityIndex)
{
	for (int i = 0; i < index; i++)
	{
		if (systems[i] && systems[i]->GetIsActive())
		{
			systems[i]->Update(deltaTime, entityIndex);
		}
		else break;
	}
}