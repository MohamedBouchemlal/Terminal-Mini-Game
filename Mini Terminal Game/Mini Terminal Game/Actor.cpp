#include "Actor.h"

Actor::Actor(char Name, int StartpositionY) : _Name(Name), _StartPosition(StartpositionY)
{
	_Y = StartpositionY;	
}


Actor::~Actor()
{
}

char& Actor::getName()
{
	return _Name;
}

int& Actor::getPositionY()
{
	return _Y;
}
int& Actor::getPositionX()
{
	return _X;
}


