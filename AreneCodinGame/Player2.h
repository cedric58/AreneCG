#pragma once
#include "Player.h"
class CPlayer2 :
	public CPlayer
{
public:
	CPlayer2();
	~CPlayer2();

	//static void Run(CPlayer *instance/*, CGame &game*/);
	virtual void Run();
};

