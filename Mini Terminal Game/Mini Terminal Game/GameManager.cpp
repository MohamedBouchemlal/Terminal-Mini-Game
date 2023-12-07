#include "GameManager.h"
#include<iostream>
#include<conio.h>
#include<thread>
#include<cstdlib>
using namespace std;

GameManager::GameManager(Player& P) : _P(&P)
{
	Over = false;
	Score = 0;
	Level = 1;
	Leveluper = 0;
	spawner = 100;
	Zaehler = (float)spawner;
	ZaehlerTime = 0.2f;
}

void GameManager::ChooseOption()
{
	cout << "          _ _              _  ___ _ _             _ " << endl;
	cout << "    /\\   | (_)            | |/ (_) | |           | |" << endl;
	cout << "   /  \\  | |_  ___ _ __   | ' / _| | | ___ _ __  | |" << endl;
	cout << "  / /\\ \\ | | |/ _ \\ '_ \\  |  < | | | |/ _ \\ '__| | |" << endl;
	cout << " / ____ \\| | |  __/ | | | | . \\| | | |  __/ |    |_|" << endl;
	cout << "/_/    \\_\\_|_|\\___|_| |_| |_|\\_\\_|_|_|\\___|_|    (_)" << endl;

	cout << endl;
	cout << "		1- Start !" << endl;
	cout << "		2- Exit" << endl;

	int c = _getch() - '0';
	switch (c)
	{
	case 1:
		system("cls");
		Gameplay();
		break;

	case 2:
		system("exit");
		break;
	default:
		break;
	}
}

void GameManager::Gameplay()
{
	//StartSpawn();
	while (!Over) {
		LevelSpawnManager();
		ScoreManager();

		//PlayerMovement
		_P->Laufen();

		//AlienMovement
		for (auto alien : _Aliens) {
			if (alien->getPositionX() == _P->getPositionX())
				GameOver();

			alien->Laufen();
		}

		//Bullet(if shot)
		for (auto bullet : _P->getBullets()) {
			bullet->releaseBullet();

			if (bullet->getPositionX() > mapWidth) {
				delete(bullet);
				_P->eraseBullet(bullet);
			}
		}

		//Render
		RenderMap();

		cout << endl;
		cout << "Beweg dich mit W & S und schiess mit F " << endl;
		cout << "Lass die Aliens dich nicht zu erreichen! " << endl;
		cout << endl;
		cout << "Level: " << Level << endl;
		cout << "Score: " << Score << endl;
		this_thread::sleep_for(std::chrono::milliseconds(400));
		system("cls");
	}

}

void GameManager::LevelSpawnManager()
{	//Aliens spawn laut des Niveaus
	if (Zaehler >= spawner) {
		SpawnEnemyWave();
		Zaehler = 0;
		Leveluper++;
	}
	else
		Zaehler += Zaehler + ZaehlerTime;

	if (Leveluper >= 5) {
		Level++;
		ZaehlerTime += 0.2;
		Leveluper = 0;
	}
}

void GameManager::RenderMap() {
	//Update Map
	for (int y = 1; y < 9; y++) {
		for (int x = 1; x < 28; x++) {
			bool cellEmpty = true;
			//Player
			if (_P->getPositionY() == y && _P->getPositionX() == x) {
				Map[y][x] = _P->getName();
				cellEmpty = false;
				continue;
			}
			//Enemies				
			for (auto alien : _Aliens) {
				if (alien->getPositionY() == y && alien->getPositionX() == x) {
					Map[y][x] = alien->getName();
					cellEmpty = false;
				}
			}
			//Bullets				
			for (auto bullet : _P->getBullets()) {
				if (bullet->getPositionY() == y && bullet->getPositionX() == x) {
					Map[y][x] = bullet->getName();
					cellEmpty = false;
				}
			}
			if (cellEmpty)
				Map[y][x] = ' ';
		}
	}

	//Render Map
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 30; x++) {
			cout << Map[y][x];
		}
		cout << endl;
	}
}

void GameManager::SpawnEnemyWave()
{
	for (int i = 0; i < Level; i++) {
		int Random = rand() % (1 - 9 + 1) + 1;
		_Aliens.push_back(new Alien('E', Random));
	}
}

void GameManager::ScoreManager()
{
	for (auto bullet : _P->getBullets()) ///(int i = 0; i < _P->getBullets().size(); i++)
	{
		for (int j = 0; j < _Aliens.size(); j++)
			if (bullet->getPositionY() == _Aliens.at(j)->getPositionY() && abs(bullet->getPositionX() - _Aliens.at(j)->getPositionX()) <= 1) {
				cout << "Alien Killed";
				Score++;
				
				delete(_Aliens.at(j));
				_Aliens.erase(_Aliens.begin() + j);

				delete(bullet);
				_P->eraseBullet(bullet);
			}
	}

}

void GameManager::GameOver()
{
	system("cls");
	Over = true;
	cout << "	Game Over !";
	this_thread::sleep_for(std::chrono::milliseconds(2000));
}

GameManager::~GameManager()
{
}
