#pragma once
class Actor
{
protected:
	char _Name;
	int _StartPosition;
	int _X, _Y;

public:
	Actor(char Name, int StartpositionY);
	~Actor();
	virtual void Laufen() = 0;

	char& getName();

	int& getPositionX();
	int& getPositionY();
};

