/*
CloverGame

The core class for an actual running game.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __CLOVERGAME_H
#define __CLOVERGAME_H

namespace CloverEngine
{
	/*
	Think of this as the game's entry point, whereas CloverEngine is the engine's entry point.
	CloverEngine's Run() needs a CloverGame passed in in order to be called. Children of
	CCloverGame can extend the Handler classes in order to offer interactivity. The
	instance of CloverGame that you pass into CloverEngine::Run() will be deleted during
	the engine's shutdown.
	*/
	class CCloverGame
	{
	public:
		CCloverGame() { }
		virtual ~CCloverGame() { }

		// Called once during CloverEngine's startup. Use this to initialize needed resources.
		virtual void InitializeGame() { } ;

		/*
		Called once during CloverEngine's shutdown. Use this if you need to pre-process
		anything before the final shutdown/deletion of objects.
		*/
		virtual void ShutdownGame() { }
	};
}

#endif