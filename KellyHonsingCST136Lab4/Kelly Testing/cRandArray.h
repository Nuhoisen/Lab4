#ifndef CRANDARRAY_H
#define CRANDARRAY_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::string;
using std::time;
using std::rand;
using std::cout;

class cRandArray
{
public:
	string * RandNumGen(int cArg, char * vArg[]);

	cRandArray();
	~cRandArray();
};

#endif