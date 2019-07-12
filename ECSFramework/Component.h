#pragma once

class Component
{
public:
	enum class ComponentType
	{
		Position
	};

private:
	ComponentType type;
	size_t size;
};