#pragma once
#include "Bullet.h"
#include "Actor.h"
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

class Player : public Actor
{
private:
	vector<Bullet*> _B;

public:
	Player(char Name, int Startposition);
	~Player();

	void Laufen() override;

	vector<Bullet*>& getBullets();
	void eraseBullet(Bullet* i);
};

