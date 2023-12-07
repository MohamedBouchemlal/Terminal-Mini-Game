#pragma once
#include"Actor.h"
class Alien : public Actor
{

public:
	Alien(char Name, int StartpositionY);
	~Alien();

	void Laufen() override;
};

