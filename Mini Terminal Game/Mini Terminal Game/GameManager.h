#pragma once
#include"Player.h"
#include"Alien.h"
#include<vector>
#include<cstdlib>
class GameManager
{
	Player* _P;
	vector <Alien*> _Aliens;
	int Score;
	int Level;
	int Leveluper;
	int spawner;
	float Zaehler;
	float ZaehlerTime;
	bool Over;


public:

	GameManager(Player& P);
	~GameManager();

	char Map[10][30] = { "-----------------------------",
						"|                           |",
						"|                           |",
						"|                           |",
						"|                           |",
						"|                           |",
						"|                           |",
						"|                           |",
						"|                           |",
						"-----------------------------"
	};

	const static int mapWidth = 30 - 2;
	const static int mapHeight = 10 - 2;

	void ChooseOption();
	void Gameplay();
	void LevelSpawnManager();
	void SpawnEnemyWave();
	void ScoreManager();
	void GameOver();
	void RenderMap();

};

