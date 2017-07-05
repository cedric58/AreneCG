#include "stdafx.h"
#include "Player2.h"


CPlayer2::CPlayer2()
{
}


CPlayer2::~CPlayer2()
{
}
/*
void CPlayer2::Run(CPlayer *instance)
{
	LOG("Player ", instance->id.c_str(), " started.");
	while (instance->IsAlive())
	{
		instance->bNextRound = false;
		//DEBUT ALGO
		instance->action = "REMOVE 2";
		//SORTIE

		while (!instance->NextRound() && instance->IsAlive())
		{
			//LOG(instance->action.c_str(), " action ", instance);
			Sleep(1);
		}
	}
}*/

void CPlayer2::Run()
{	
	action = "REMOVE 2";
	//SORTIE		
}
