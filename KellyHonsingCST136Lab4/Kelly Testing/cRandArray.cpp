//Kelly Honsinger
#include "cRandArray.h"
string * cRandArray::RandNumGen(int cArg, char * vArg[])
{
	string * copy = new string[cArg];
	for (int e = 0; e < cArg; e++)
	{
		copy[e] = vArg[e];

	}


	srand(time(nullptr));
	for (int i = 2; i < cArg; i++)
	{
		int rNum = 1 + (rand() % (int)(cArg -3 +1));

		string temp = copy[rNum]; //store current index in temp

		copy[rNum] = copy[i];  //random index will be sized

		copy[i] = temp;
	}
	return copy;
}

cRandArray::cRandArray()
{

}


cRandArray::~cRandArray()
{

}



