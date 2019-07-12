#pragma once
class IComponentManager
{
public:
	virtual void DeleteComponent(unsigned int entity) = 0;
};