#include "stdafx.h"
#include "Player1.h"


CPlayer1::CPlayer1()
{
}


CPlayer1::~CPlayer1()
{
}
/*
void CPlayer1::Run(CPlayer *instance)
{

	LOG("Player ", instance->id.c_str(), " started.");
	while (instance->IsAlive())
	{
		instance->bNextRound = false;
		//DEBUT ALGO



		instance->action = "REMOVE 1";
		//SORTIE

		while (!instance->NextRound() && instance->IsAlive())
		{
			//LOG(instance->action.c_str(), " action ", instance);
			Sleep(1);
		}
	}
}*/

void CPlayer1::Run()
{	
	std::ostringstream oss;
	oss << "REMOVE " << valueToPlay;
	action = oss.str();

	//SORTIE		
}