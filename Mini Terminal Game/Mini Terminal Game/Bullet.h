#pragma once
class Bullet
{
	char _Name = '-';
	int _BulletX;
	int _BulletY;
	bool released;

public:
	Bullet(int x, int y, bool t);
	~Bullet();

	void releaseBullet();
	void setreleased(bool a);

	char& getName();

	int& getPositionX();
	int& getPositionY();
};

