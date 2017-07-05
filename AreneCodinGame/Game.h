#pragma once
#include "Player.h"
#include <chrono>
#include "fastrand.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "util.h"

using namespace std;
using namespace std::chrono;

class CGame
{

public:
	CGame();
	CGame(CPlayer *lplayer1, CPlayer *lplayer2);
	~CGame();

CPlayer *player1;
CPlayer *player2;

int round = 0;
int nbAllumettes;

system_clock::time_point s_start; 
duration<double>         s_duration;

bool GameIsEnded();
void Run();
void Start();
void End();
bool NextRound();
//Vérifie si l'entrée du joueur est valide
bool IsValid(std::vector<std::string> action);

//Donne les entrées aux joueurs;
void LoadData();

};

