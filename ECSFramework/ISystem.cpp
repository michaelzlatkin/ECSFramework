#include "ISystem.h"



void ISystem::Start()
{
	isActive = true;
}

void ISystem::End()
{
	isActive = false;
}

bool ISystem::GetIsActive()
{
	return isActive;
}