#include "Player.h"
#include<conio.h>
#include<algorithm>

Player::Player(char Name, int Startposition) : Actor(Name, Startposition)
{
	_X = 2;
}

void Player::Laufen()
{
	if (_kbhit()) {
		char c = _getch();
		switch (c) {
		case 'w':
			_Y--;
			break;

		case 's':
			_Y++;
			break;

		case 'f':
			_B.push_back(new Bullet(_X + 1, _Y, true));
			break;

		default:
			break;
		}
		_Y = clamp(_Y, 1, 8);
	}
}

vector<Bullet*>& Player::getBullets()
{
	return _B;
}

void Player::eraseBullet(Bullet* bullet)
{
	auto it = find(_B.begin(), _B.end(), bullet);
	_B.erase(it);
}


Player::~Player()
{
}

