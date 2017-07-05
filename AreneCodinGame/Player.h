#pragma once

#include "Log.h"
//#include "Game.h"
#include <windows.h>
#include <thread> 
#include <iostream>
#include <sstream>

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	string id;
	string action;
	bool bNextRound;
	bool bIsAlive;

	int valueToPlay;

	//std::stringstream stream; 

	bool NextRound() {
		return bNextRound;
	}

	bool IsAlive() {
		return bIsAlive;
	}

	void ReInitAction() { action = ""; bNextRound = true; }
	void Start();
	
	void OutStream(std::stringstream &InputStream);

	static void RunStatic(CPlayer *instance);
	virtual void Run() = 0;

};

