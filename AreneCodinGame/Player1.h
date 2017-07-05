#pragma once
#include "Player.h"

class CPlayer1 :
	public CPlayer
{
public:
	CPlayer1();
	~CPlayer1();

	//static void Run(CPlayer *instance/*, CGame &game*/);
	virtual void Run();
};

