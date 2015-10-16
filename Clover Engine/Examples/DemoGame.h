/*
DemoGame

Example of how to set up your own child of CloverGame

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __DEMOGAME_H
#define __DEMOGAME_H

#include "Source\Core\CloverGame.h"
#include "Source\Handler\UpdateHandler.h"
#include "Source\Handler\KeyHandler.h"
#include "Source\Handler\MouseHandler.h"
#include "Source\Handler\DrawHandler.h"
#include "Source\IO\VirtualWindow.h"
#include <string>

namespace CloverEngine
{
	struct SKeyInfo;
	struct SMouseInfo;

	/*
	Example of how to set up a basic single-class game that has all handlers, including drawing. Normally drawing would be
	farmed out to sprites, etc., but this is just to show how to use things. The engine will automatically delete whichever
	CloverGame instance was passed in to the CloverEngine::Run() method, and as such the memory for these handlers will be
	dealt with automatically. However, any extra classes that you create, memory will have to be managed manually. Handlers
	register themselves with the Engine automatically, but the Engine does not delete them on shutdown (that's what the
	ShutdownGame() method here is for).

	>> SEE DEMOGAME.CPP FOR IMPLEMENTATIONS <<
	*/
	class CDemoGame : public CCloverGame, public CUpdateHandler, public CKeyHandler, public CMouseHandler, public CDrawHandler
	{
		// A window to draw to.
		CVirtualWindow* m_Window;

		// An example shader for said window.
		CShader* m_Shader;

	public:
		/*
		Constructor/Destructor are not normally used by CloverGame children, initialization is done in InitializeGame while
		clean up is handled in ShutdownGame prior to the object actually being deleted.
		*/
		CDemoGame();
		virtual ~CDemoGame();

		// Called a single time immediately before the game loop starts. Use this as initialization.
		void InitializeGame();
		// Called a single time immediately after the game loop ends. Use this as cleanup.
		void ShutdownGame();

		// Called once at the start of each engine tick. If needed within Update, store relevant input in member variables.
		void KeyboardEvent(const CloverEngine::SKeyInfo& aEvent);
		void MouseEvent(const CloverEngine::SMouseInfo& aEvent);

		// Called immediately after input, once every engine tick. Elapsed time is in seconds.
		void Update(double aDelta);
		
		// Called once at the end of each engine tick. Here's where you make things look pretty.
		void Draw();
	};
}

#endif