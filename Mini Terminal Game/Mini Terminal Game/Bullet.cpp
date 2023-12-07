#include "Bullet.h"

Bullet::Bullet(int x, int y, bool t) : _BulletX(x), _BulletY(y), released(t)
{
}


Bullet::~Bullet()
{
}


void Bullet::releaseBullet()
{
	if (released == true)
		_BulletX++;
}

void Bullet::setreleased(bool a)
{
	released = true;
}

char& Bullet::getName()
{
	return _Name;
}

int& Bullet::getPositionX()
{
	return _BulletX;
}

int& Bullet::getPositionY()
{
	return _BulletY;
}


