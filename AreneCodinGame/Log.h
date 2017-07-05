#pragma once
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define LOG(...)   cerr , __VA_ARGS__ ; cerr << endl;
#define LOGS(...)  cerr , __VA_ARGS__

template <typename T>
ostream& operator,(ostream& out, const T& t)
{
	out << t;

	return out;
}
#else
#define LOG(...)
#define LOGS(...) 
#endif


// Overloaded version to handle all those special std::endl and others...
/*ostream& operator,(ostream& out, ostream&(*f)(ostream&))
{
	out << f;

	return out;
}*/