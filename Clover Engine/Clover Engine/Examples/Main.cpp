/*
Main

CloverEngine is a console-based game engine for Windows. To begin using the
engine, include CloverEngine.h at the top of your project. This is the entry
point of the engine. Look at CloverGame.h for the primary game singleton.

Creator:	Charlotte C. Brown
File Date:	October 5th, 2015
Version:	0.0
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"
#include "Examples\DemoGame.h"

int main()
{
	/*
	In your main() function, the only thing you should be doing with CloverEngine is passing in
	an instance of the game that you wish to run. Technically speaking you could put a wrapper
	around this and have a menu to select which game to run, but do NOT call any CloverEngine
	functions from outside of the running game.

	The hook into your actual game code is within the CloverGame that you passed in.

	Make sure you do NOT do anything with pdcurses outside of engine functionality either, it
	could potentially horribly butcher things if they start changing unexpectedly.
	*/
	CloverEngine::CCloverEngine::GetInstance()->Run(new CloverEngine::CDemoGame());
	return 0;
}