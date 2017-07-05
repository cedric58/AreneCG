#include "stdafx.h"
#include "Game.h"

CGame::CGame()
{
}

CGame::CGame(CPlayer *lplayer1, CPlayer *lplayer2)
{
	player1 = lplayer1;
	player2 = lplayer2;
}


CGame::~CGame()
{
}


bool CGame::GameIsEnded()
{
	//TODO IMPLEMENTER LA FIN DE JEU
	if (round > 200 || !player1->bIsAlive || !player2->bIsAlive)
	{
		LOG("Le jeu est terminé");
		return true;
	}

	return false;
}

void CGame::Start()
{
	/*player1.Start();
	player2.Start();*/
	//TODO GENERER LE JEU
	nbAllumettes = RAND() % 90 + 10;
	LOG("nbAllumettes :",nbAllumettes);
}

void CGame::Run()
{
	//if(round == 1)
	LOG("");
	LOG("Round n°", round);
	LOG("Distribution des datas aux joueurs");
	LoadData();

	bool bContinue = true;
	double limit = (round == 1) ? 1.0 : 0.050;

	s_start = system_clock::now();

	//Attente des actions des joueurs
	while (bContinue)
	{
		bContinue = false;
		//LOG("WAIT FOR... ", player1->action.c_str(), " ", player2->action.c_str());
		if (player1->action.length() == 0 && player1->bIsAlive) bContinue = true;
		if(player2->action.length() == 0 && player2->bIsAlive) bContinue = true;

		s_duration = system_clock::now() - s_start;
		if (s_duration.count() > limit)
		{
			LOG("Timeout !");
			bContinue = false;
		}
		
		Sleep(1);
	}

	//Vérification des inputs
	
	if (player1->bIsAlive)
	{
		if (player1->action.length() == 0)
		{
			player1->bIsAlive = false;
			LOG("Player 2 is dead");
		}
		else
		{
			LOG("Player 1 DO THIS : ", player1->action.c_str());
		}
	}

	if (player2->bIsAlive)
	{
		if (player2->action.length() == 0)
		{
			player2->bIsAlive = false;
			LOG("Player 2 is dead");
		}
		else
		{
			LOG("Player 2 DO THIS : ", player2->action.c_str());
		}
	}
	
	vector<string> actionPlayer1 = split(player1->action, ' ');
	if (!IsValid(actionPlayer1) && player1->bIsAlive)
	{
		LOG("Player 1 have invalid input !");
		player1->bIsAlive = false;
	}

	vector<string> actionPlayer2 = split(player2->action, ' ');
	if (!IsValid(actionPlayer2) && player2->bIsAlive)
	{
		LOG("Player 2 have invalid input !");
		player2->bIsAlive = false;
	}

	//MISE A JOUR DU JEU
	if (player1->bIsAlive)
	{
		if (nbAllumettes < stoi(actionPlayer1[1]))
		{
			LOG("Joueur 1 a perdu !");
			player1->bIsAlive = false;
			return;
		}
		else
		{
			nbAllumettes -= stoi(actionPlayer1[1]);
		}
	}

	if (player2->bIsAlive)
	{
		if (nbAllumettes < stoi(actionPlayer2[1]))
		{
			LOG("Joueur 2 a perdu !");
			player2->bIsAlive = false;
			return;
		}
		else
		{
			nbAllumettes -= stoi(actionPlayer2[1]);
		}
	}

	//Reinit des actions des joueurs
	player1->ReInitAction();
	player2->ReInitAction();
	round++;
	LOG("");
}

bool CGame::NextRound()
{
	return false;
}

void CGame::End()
{
	player1->bIsAlive = false;
	player2->bIsAlive = false;
}

bool CGame::IsValid(std::vector<std::string> action)
{
	//TO DO Verifier les entrées
	if (action.size() != 2)
	{
		return false;
	}

	if (action[0].compare("REMOVE") != 0) return false;

	int i_dec = std::stoi(action[1]);

	if (i_dec < 1 || i_dec > 3) return false;

	return true;

}

void CGame::LoadData()
{
	//TO DO Distribuer le jeu de données aux deux joueurs
	std::stringstream stream, stream2;
	//première ligne
	stream << "2\n";
	//deuxième ligne
	stream << nbAllumettes << " " << 10 << "\n";

	stream2 << "4\n";
	//deuxième ligne
	stream2 << nbAllumettes << " " << 12 << "\n";

	LOG("Player 1 Read Input : ");
	player1->OutStream(stream);
	LOG("Player 2 Read Input : ");
	player2->OutStream(stream2);

}