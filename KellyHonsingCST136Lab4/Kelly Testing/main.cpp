/*Kelly Honsinger
Date Created:10/18/2015
Last Modification Date 11/23/2015
Lab Number: 7
File Name: main.cpp

Overview:
This Program is in the intermediate stage of becoming a game.  This game will display a sequence of images 
on the screen in random order.  A 'special' image will be amoungst these that the user must pay attention to. To
trigger the loop the user must direct a dot so that it collides with a start image.  After that a image loop will start that
will display a sequence of images in random order.  My "new feature" to my game is encorporation of the vector template from the STL library.
This vector consists of bools and is used to check that my function correctly returned the right data.  My other use of a stl library construct is 
the use of the queue template found in the "LoadSurface()" function of the surface manager class.  The queue "pushes" in a sdl texture and does a series
of things to it before it is "popped" or removed.

Input: 
The program takes its input via the command line arguments.

Output:
The program outputs the images that the command line arguments point to.
*/
#include "cGameLoop.h"
int main(int argc, char * argv[])
{
	
	cGameLoop StartGame(argv, argc);	//object that is passed command line args
	StartGame.RandNumGen(argv, argc);
	StartGame.BeginGame();				//object calls method to start game
	
	return 0;
}


