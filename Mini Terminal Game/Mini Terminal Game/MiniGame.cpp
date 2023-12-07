#include "GameManager.h"
#include "Player.h"
#include"Bullet.h"
#include <iostream>
#include<thread>
#include<conio.h>

using namespace std;
int main()
{
	srand(time(NULL));

	Player P('P', 5);
	GameManager myGameManager(P);
	myGameManager.ChooseOption();


}
