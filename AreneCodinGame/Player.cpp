#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	bNextRound = false;
	bIsAlive = true;
}


CPlayer::~CPlayer()
{
}

void CPlayer::Start()
{
	
}

void CPlayer::OutStream(std::stringstream &InputStream)
{
	//TODO LIRE LES ENTREES
	int nbPlayer, nbAllumettes, dix;
	InputStream >> nbPlayer;
	InputStream >> nbAllumettes >> dix;
	LOG(nbPlayer, " ", nbAllumettes, " ", dix);
}

void CPlayer::RunStatic(CPlayer *instance)
{
	LOG("Player ", instance->id.c_str(), " started.");
	while (instance->IsAlive())
	{
		instance->bNextRound = false;
		//DEBUT ALGO
		instance->Run();
		//SORTIE

		while (!instance->NextRound() && instance->IsAlive())
		{
			//LOG(instance->action.c_str(), " action ", instance);
			Sleep(1);
		}
	}
}


/*void CPlayer::Run(CPlayer *instance)
{

	LOG("Player ", instance->id.c_str(), " started.");
	while (instance->IsAlive())
	{
		instance->bNextRound = false;
		//DEBUT ALGO


		
		instance->action = "MOVE " + instance->id;
		//SORTIE

		while (!instance->NextRound())
		{
			//LOG(instance->action.c_str(), " action ", instance);
			Sleep(1);
		}
	}
}*/
