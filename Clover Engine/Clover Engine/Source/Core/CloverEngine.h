/*
CloverEngine

The singleton that manages everything about the game engine.

Creator:	Charlotte C. Brown
File Date:	October 4th, 2015
Version:	0.0
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __CLOVERENGINE_H
#define __CLOVERENGINE_H

#include "PDCurses\Include\curses.h"
#include <Windows.h>
#include <signal.h>
#include <assert.h>
#include <string>
#include <sstream>
#include <tchar.h>
#include <time.h>
#include <vector>
#include <memory>

#include "Source\IO\InputTypes.h"
#include "Source\IO\Colours.h"
#include "Source\Core\CloverGame.h"
#include "Source\Component\Component.h"
#include "Source\Core\GameObject.h"
#include "Source\Component\Transform.h"
#include "Source\Component\DrawBuffer.h"
#include "Source\Component\Handler\KeyHandler.h"
#include "Source\Component\Handler\MouseHandler.h"
#include "Source\Component\Handler\UpdateHandler.h"
#include "Source\Component\Handler\DrawHandler.h"
#include "Source\Component\Handler\WindowHandler.h"
#include "Source\IO\VirtualWindow.h"
#include "Source\IO\Shader.h"

namespace CloverEngine
{
	/*
	CloverEngine is responsible for everything related to the engine itself. This class
	keeps track of stuff like global settings (tick rates, window size, etc.), is responsible for
	the core game loop, stores all registered handlers and pushes all events out to them. The
	engine will run the game loop and pass events to the given CloverGame object, as well as handle
	deleting the CloverGame during the engine shutdown process.
	*/
	class CCloverEngine
	{
	public:
		// The maximum update ticks per second. Set to 0 for unlimited.
		const unsigned int CE_TICK_RATE = 30;
		
		// The default cursor size. 0 = off, 1 = normal, 2 = full height.
		const unsigned char CE_DEF_CURSOR_SIZE = 0;
		
		// Does what it sounds like it does!
		const bool CE_FULLSCREEN = false;
		
		// Width in characters. Does nothing in fullscreen mode.
		const unsigned short CE_SCREEN_WIDTH = 200;
		
		// Height in lines. Does nothing in fullscreen mode.
		const unsigned short CE_SCREEN_HEIGHT = 60;
		
		// Key that will shut down the engine. 0 = disabled.
		const unsigned short CE_SHUTDOWN_KEY = VK_ESCAPE;

	private:
		// The sole, forever lonely, instance of our singleton.
		static CCloverEngine* m_Instance;

		// The game that we will be running
		CCloverGame* m_Game;

		// Contains all registered update handlers
		std::vector<CUpdateHandler*> m_UpdateHandlers;

		// Contains all registered mouse handlers
		std::vector<CMouseHandler*> m_MouseHandlers;

		// Contains all registered key handlers
		std::vector<CKeyHandler*> m_KeyHandlers;

		// Contains all registered draw handlers
		std::vector<CDrawHandler*> m_DrawHandlers;

		// Contains all registered window handlers
		std::vector<CWindowHandler*> m_WindowHandlers;

		// Has the program been asked to terminate?
		bool m_Quit;

		// Has the game loop been initiated?
		bool m_Running;

		// The previous frame's delta time, in seconds.
		double m_DeltaTime;

		// The most recent mouse event.
		SMouseInfo m_LastMouseEvent;

		// The most recent keyboard event.
		SKeyInfo m_LastKeyboardEvent;

		// No manual instantiation.
		CCloverEngine();

		// Initializes the window and some settings.
		void Startup();

		// Intitializes all colour mixtures.
		void CreateDefaultColours();

		// Shuts down all engine operations.
		void Shutdown();

		// Stops the window from being resized.
		void StopResize();

		// Called every tick. Delta time is in seconds.
		void Update(const double& aDeltaTime);

		// Mouse events are sent here.
		void MouseEvent(const SMouseInfo& aEvent);

		// Keyboard events are sent here.
		void KeyboardEvent(const SKeyInfo& aEvent);

		// Called every tick. Draws stuff to the screen.
		void Draw();

	public:
		~CCloverEngine();

		// Gets the pointer to the current instance of the engine.
		static CCloverEngine* GetInstance();

		/*
		Starts up the main game loop. This must be called as the final action after
		you have set all of the attributes for the engine.
		*/
		void Run(CCloverGame* aGame);

		/*
		Call this method to inform the engine that you wish to terminate the program.
		Proper shutdown will immediately follow.
		*/
		void Quit() { m_Quit = true; }

		// Add an update handler to the engine.
		void RegisterUpdateHandler(CUpdateHandler* aHandler);

		// Add a mouse handler to the engine.
		void RegisterMouseHandler(CMouseHandler* aHandler);

		// Add a key handler to the engine.
		void RegisterKeyHandler(CKeyHandler* aHandler);

		// Add a draw handler to the engine.
		void RegisterDrawHandler(CDrawHandler* aHandler);

		// Add a window handler to the engine.
		void RegisterWindowHandler(CWindowHandler* aHandler);

		// Removes an update handler from the engine. Returns true if the handler was found and removed.
		bool RemoveUpdateHandler(CUpdateHandler* aHandler);

		// Removes a mouse handler from the engine. Returns true if the handler was found and removed.
		bool RemoveMouseHandler(CMouseHandler* aHandler);

		// Removes a key handler from the engine. Returns true if the handler was found and removed.
		bool RemoveKeyHandler(CKeyHandler* aHandler);

		// Removes a draw handler from the engine. Returns true if the handler was found and removed.
		bool RemoveDrawHandler(CDrawHandler* aHandler);

		// Removes a window handler from the engine. Returns true if the handler was found and removed.
		bool RemoveWindowHandler(CWindowHandler* aHandler);

		// Get the previous frame's delta time, in seconds.
		double GetLastDeltaTime() { return m_DeltaTime; }

		// Get the most recent mouse event.
		SMouseInfo GetLastMouseEvent() { return m_LastMouseEvent; }

		// Get the most recent keyboard event.
		SKeyInfo GetLastKeyEvent() { return m_LastKeyboardEvent; }
	};
}

#endif