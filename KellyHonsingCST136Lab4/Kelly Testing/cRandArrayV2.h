#ifndef CRANDARRAY2_H
#define CRANDARRAY2_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::string;
using std::time;
using std::rand;
using std::cout;

class cRandArrayV2
{
public:
	string * RandFileGen(int randImageCount, int ArgC, string * ArgV);

	cRandArrayV2();
	virtual ~cRandArrayV2();
private:
	string * copy;
};

#endif