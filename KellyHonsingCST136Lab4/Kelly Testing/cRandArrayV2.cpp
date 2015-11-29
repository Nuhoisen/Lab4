//Kelly Honsinger
#include "cRandArrayV2.h"

cRandArrayV2::cRandArrayV2()
{

}


cRandArrayV2::~cRandArrayV2()
{
	delete[] copy;
}


string *cRandArrayV2::RandFileGen(int randImageCount, int argC, string* argV)
{
	copy = new string[argC];
	for (int e = 0; e < argC; e++)
	{
		copy[e] = argV[e];
	}


	srand(time(nullptr));
	for (int i = 1; i < randImageCount; i++)
	{
		int rNum = 1 + (rand() % (int)(randImageCount - 3 + 1));

		string temp = copy[rNum]; //store current index in temp

		copy[rNum] = copy[i];  //random index will be sized

		copy[i] = temp;
	}
	return copy;
}



