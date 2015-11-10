/*Kelly Honsinger
Date Created:10/18/2015
Last Modification Date 11/9/2015
Lab Number: 5
File Name: main.cpp

Overview:
This Program is the start to a game I'm making.  This game will display a sequence of images 
on the screen in random order.  A 'special' image will be amoungst these that the user must pay attention to.
Once the image loop stops, the user will be able to look through all the images again in a user controlled game loop 
to find the two images that preceeded and proceeded the 'special' image.  

Input: 
The program takes its input via the command line arguments.

Output:
The program outputs the images that the command line arguments point to.
*/
#include "cGameLoop.h"

int main(int argc, char * argv[])
{
	cGameLoop StartGame(argv, argc);	//object that is passed command line args

	StartGame.BeginGame();	//object calls method to start game
	
	return 0;
}


