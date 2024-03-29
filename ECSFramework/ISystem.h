#pragma once
#include "EngineConstants.h"

class ISystem
{
public:
	ISystem() = default;

	virtual ~ISystem() = default;

	virtual void Start();

	virtual void Update(const float &deltaTime, const unsigned int &entityIndex) = 0;

	virtual void End();

	const bool GetIsActive();

	void SetIsActive(bool isActive);

protected:
	//We don't define a container for the components in here directly
	//The user might need more than one component list or none at all, we leave this up to them
	bool mIsActive = false;
};