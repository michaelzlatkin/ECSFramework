#include "ISystem.h"



void ISystem::Start()
{
	mIsActive = true;
}

void ISystem::End()
{
	mIsActive = false;
}

const bool ISystem::GetIsActive()
{
	return mIsActive;
}

void ISystem::SetIsActive(bool isActive)
{
	mIsActive = isActive;
}