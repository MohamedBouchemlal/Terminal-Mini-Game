#include "Alien.h"

Alien::Alien(char Name, int StartpositionY) : Actor(Name, StartpositionY)
{	
	_X = 27;
}


Alien::~Alien()
{
}

void Alien::Laufen()
{
	_X--;
}



