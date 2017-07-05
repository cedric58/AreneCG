// AreneCodinGame.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <array>
#include <vector>
#include <list>
#include <cmath>
#include <limits>
#include <chrono>
#include <thread> 
#include "AllPlayer.h"
#include "Game.h"
#include "sRange.h"
#include <fstream>
#include <chrono>

using namespace std;

using namespace std::chrono;

system_clock::time_point s_start;
duration<double>         s_duration;

int countPlayer1Win = 0;
int countPlayer2Win = 0;
int countTie = 0;

#define NBPARTIE 50

ofstream fichier("test.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

void DisplayStat()
{
	LOG("Nombre partie jouée : ", NBPARTIE);
	LOG("Nombre victoires joueur 1 : ", countPlayer1Win, " (", (100/NBPARTIE)*countPlayer1Win,"%)");
	LOG("Nombre victoires joueur 2 : ", countPlayer2Win, " (", (100/NBPARTIE)*countPlayer2Win,"%)");
	LOG("Nombre ex-aequo : ", countTie, " (", (100 / NBPARTIE)*countTie, "%)");
}

void WriteStat()
{
	s_duration = system_clock::now() - s_start;
	fichier << endl << "Nombre partie jouée : " << NBPARTIE << " (en " << s_duration.count() * 1000 << " ms)" << endl;
	fichier << "Nombre victoires joueur 1 : " << countPlayer1Win << " (" << (100 / NBPARTIE)*countPlayer1Win << "%)" << endl;
	fichier << "Nombre victoires joueur 2 : " << countPlayer2Win << " (" << (100 / NBPARTIE)*countPlayer2Win << "%)" << endl;
	fichier << "Nombre ex-aequo : " << countTie << " (" << (100 / NBPARTIE)*countTie << "%)" << endl << endl;
}

void reinitStat()
{
	countPlayer1Win = 0;
	countPlayer2Win = 0;
	countTie = 0;
}

int main()
{
	if (!fichier)  // si l'ouverture a réussi
	{
		cerr << "Erreur à l'ouverture !" << endl;
	}
	
		

	//int N = 2;
	//thread my_thread[N];
	long id; 

	sRange<int> value(1,3,1, "On fait varier le paramètre du REMOVE du player 1 de 1 à 3");
	int valueToPlay;
	while (value.NextValue(valueToPlay))
	{
		reinitStat();

		s_start = system_clock::now();

		for (int i = 0; i < NBPARTIE; i++)
		{
			CPlayer *player1 = new CPlayer1();
			
			CPlayer *player2 = new CPlayer2();

			player1->valueToPlay = valueToPlay;

			player1->id = "1";
			player2->id = "2";

			std::thread first(&CPlayer::RunStatic, player1);
			Sleep(1);
			std::thread second(&CPlayer::RunStatic, player2);
			Sleep(1);
			CGame game(player1, player2);

			game.Start();

			while (!game.GameIsEnded())
			{
				game.Run();
			}

			if (!player1->IsAlive())
			{
				countPlayer2Win++;
				if (!player2->IsAlive())
				{
					countTie++;
				}
			}
			else if (!player2->IsAlive())
			{
				countPlayer1Win++;
			}

			game.End();

			first.join();
			second.join();
		}

		fichier << value.m_comment.c_str() << " => " << valueToPlay;
		DisplayStat();
		WriteStat();
	}

	fichier.close();

	system("PAUSE");
    return 0;
}

