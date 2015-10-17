/*
CloverEngine

The singleton that manages everything about the game.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "CloverEngine.h"

using namespace std;
using namespace CloverEngine;

CCloverEngine* CCloverEngine::m_Instance = nullptr;

CCloverEngine::CCloverEngine() : m_Quit(false), m_DeltaTime(0), m_Running(false), m_Game(nullptr)
{
	// Initial memory allocation to avoid instantly having to resize handler storage on launch
	m_UpdateHandlers.reserve(8);
	m_MouseHandlers.reserve(8);
	m_KeyHandlers.reserve(8);
	m_DrawHandlers.reserve(8);
	m_WindowHandlers.reserve(8);
}

CCloverEngine::~CCloverEngine()
{
}

CCloverEngine* CCloverEngine::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new CCloverEngine();
	}

	return m_Instance;
}

void CCloverEngine::Run(CCloverGame* aGame)
{
	// Quick check to make sure this is only called once, and that we have a valid game.
	if (m_Running || aGame == nullptr)
	{
		return;
	}
	else
	{
		m_Running = true;
		m_Game = aGame;
	}

	// Initialize curses and our general settings.
	Startup();

	// Delta time tracking vars, in seconds.
	double lastFrameTick = (double)GetTickCount();
	double frameDelta = 0.0;

	// Get the output handle.
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Get the input handle.
	HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

	// Array of recorded inputs.
	INPUT_RECORD* inputBuffer = nullptr;

	// Number of input events in the buffer.
	DWORD numInputs = 0;

	// Number of input events read.
	DWORD numInputsRead = 0;

	// Initialize our game.
	m_Game->InitializeGame();

	// Main game loop.
	while (!m_Quit)
	{
		// TODO: Figure out how to properly disable window resizing instead of having to check size and force it.
		// Don't allow window resizing.
		StopResize();

		// ========== Handle Input ==========
		// Check if there is input
		numInputsRead = 0;
		numInputs = 0;
		GetNumberOfConsoleInputEvents(hStdIn, &numInputs);

		// Do we have inputs?
		if (numInputs > 0)
		{
			// Grab all of the input events.
			inputBuffer = new INPUT_RECORD[numInputs];
			ReadConsoleInput(hStdIn, inputBuffer, numInputs, &numInputsRead);

			// Iterate through every event
			for (unsigned int i = 0; i < numInputsRead; i++)
			{
				switch (inputBuffer[i].EventType)
				{
					// Something to do with the mouse
					case MOUSE_EVENT:
					{
						SMouseInfo mouse;
						MOUSE_EVENT_RECORD mouseRecord = inputBuffer[i].Event.MouseEvent;

						// Set the mouse event info as appropriate
						mouse.m_X = mouseRecord.dwMousePosition.X;
						mouse.m_Y = mouseRecord.dwMousePosition.Y;
						mouse.m_Button = mouseRecord.dwButtonState;
						mouse.m_Modifier = mouseRecord.dwControlKeyState;
						mouse.m_Event = mouseRecord.dwEventFlags;

						// Push it to our mouse event handlers
						MouseEvent(mouse);
						break;
					}
					// Something to do with the keyboard
					case KEY_EVENT:
					{
						SKeyInfo key;
						KEY_EVENT_RECORD keyRecord = inputBuffer[i].Event.KeyEvent;

						// Set the key event info as appropriate
						key.m_Pressed = (keyRecord.bKeyDown != 0);
						key.m_Key = keyRecord.wVirtualKeyCode;
						key.m_Modifier = keyRecord.dwControlKeyState;

						// Push it to our key event handlers
						KeyboardEvent(key);
						break;
					}
				}
			}
			delete[] inputBuffer;
		}

		// ========== Handle logic ==========
		frameDelta = ((double)GetTickCount() - lastFrameTick) / 1000.0;
		lastFrameTick = (double)GetTickCount();
		Update(frameDelta);

		// ========== Handle rendering ==========
		Draw();

		// ========== End of cycle ==========
		// Global tick rate limiting.
		if (CE_TICK_RATE > 0)
		{
			Sleep((DWORD)(1000.0f / (float)CE_TICK_RATE));
		}
	}

	// Shut down the running game.
	m_Game->ShutdownGame();
	
	// Shut down curses and our engine.
	Shutdown();
}

void CCloverEngine::Startup()
{
	// RNG seeding.
	srand((unsigned int)time(NULL));

	// Get the output handle
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Window sizing variables
	SMALL_RECT windowSize;
	COORD bufferSize;

	// Check if we're supposed to launch to fullscreen mode.
	if (CE_FULLSCREEN)
	{
		SetConsoleDisplayMode(hStdOut, CONSOLE_FULLSCREEN_MODE, &bufferSize);
	}
	// No need to resize if we're running fullscreen.
	else
	{
		// Set the buffer size.
		bufferSize.X = CE_SCREEN_WIDTH;
		bufferSize.Y = CE_SCREEN_HEIGHT;
		SetConsoleScreenBufferSize(hStdOut, bufferSize);

		// Set the window size.
		windowSize.Left = 0;
		windowSize.Top = 0;
		windowSize.Right = CE_SCREEN_WIDTH - 1;
		windowSize.Bottom = CE_SCREEN_HEIGHT - 1;
		SetConsoleWindowInfo(hStdOut, TRUE, &windowSize);
	}

	// Start up curses main window.
	initscr();

	// Don't display what the user types.
	noecho();

	// Set the cursor's default visibility to the engine settings.
	curs_set(CE_DEF_CURSOR_SIZE);

	// Enable console colouring.
	start_color();

	// Initialize the default colour pairs.
	CreateDefaultColours();

	// Enable mouse input to be caught.
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_MOUSE_INPUT);
}

void CCloverEngine::CreateDefaultColours()
{
	// Make sure the terminal colours are set to full.
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_color(COLOR_RED, 1000, 0, 0);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_BLUE, 0, 0, 1000);
	init_color(COLOR_CYAN, 0, 1000, 1000);
	init_color(COLOR_MAGENTA, 1000, 0, 1000);
	init_color(COLOR_YELLOW, 1000, 1000, 0);

	// Black background pairs.
	init_pair(CE_Colour_KK, COLOR_BLACK, COLOR_BLACK);
	init_pair(CE_Colour_WK, COLOR_WHITE, COLOR_BLACK);
	init_pair(CE_Colour_RK, COLOR_RED, COLOR_BLACK);
	init_pair(CE_Colour_GK, COLOR_GREEN, COLOR_BLACK);
	init_pair(CE_Colour_YK, COLOR_YELLOW, COLOR_BLACK);
	init_pair(CE_Colour_BK, COLOR_BLUE, COLOR_BLACK);
	init_pair(CE_Colour_MK, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(CE_Colour_CK, COLOR_CYAN, COLOR_BLACK);

	// White background pairs.
	init_pair(CE_Colour_KW, COLOR_BLACK, COLOR_WHITE);
	init_pair(CE_Colour_WW, COLOR_WHITE, COLOR_WHITE);
	init_pair(CE_Colour_RW, COLOR_RED, COLOR_WHITE);
	init_pair(CE_Colour_GW, COLOR_GREEN, COLOR_WHITE);
	init_pair(CE_Colour_YW, COLOR_YELLOW, COLOR_WHITE);
	init_pair(CE_Colour_BW, COLOR_BLUE, COLOR_WHITE);
	init_pair(CE_Colour_MW, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(CE_Colour_CW, COLOR_CYAN, COLOR_WHITE);

	// Red background pairs.
	init_pair(CE_Colour_BR, COLOR_BLACK, COLOR_RED);
	init_pair(CE_Colour_WR, COLOR_WHITE, COLOR_RED);
	init_pair(CE_Colour_RR, COLOR_RED, COLOR_RED);
	init_pair(CE_Colour_GR, COLOR_GREEN, COLOR_RED);
	init_pair(CE_Colour_YR, COLOR_YELLOW, COLOR_RED);
	init_pair(CE_Colour_BR, COLOR_BLUE, COLOR_RED);
	init_pair(CE_Colour_MR, COLOR_MAGENTA, COLOR_RED);
	init_pair(CE_Colour_CR, COLOR_CYAN, COLOR_RED);

	// Green background pairs.
	init_pair(CE_Colour_BG, COLOR_BLACK, COLOR_GREEN);
	init_pair(CE_Colour_WG, COLOR_WHITE, COLOR_GREEN);
	init_pair(CE_Colour_RG, COLOR_RED, COLOR_GREEN);
	init_pair(CE_Colour_GG, COLOR_GREEN, COLOR_GREEN);
	init_pair(CE_Colour_YG, COLOR_YELLOW, COLOR_GREEN);
	init_pair(CE_Colour_BG, COLOR_BLUE, COLOR_GREEN);
	init_pair(CE_Colour_MG, COLOR_MAGENTA, COLOR_GREEN);
	init_pair(CE_Colour_CG, COLOR_CYAN, COLOR_GREEN);

	// Yellow background pairs.
	init_pair(CE_Colour_KY, COLOR_BLACK, COLOR_YELLOW);
	init_pair(CE_Colour_WY, COLOR_WHITE, COLOR_YELLOW);
	init_pair(CE_Colour_RY, COLOR_RED, COLOR_YELLOW);
	init_pair(CE_Colour_GY, COLOR_GREEN, COLOR_YELLOW);
	init_pair(CE_Colour_YY, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(CE_Colour_BY, COLOR_BLUE, COLOR_YELLOW);
	init_pair(CE_Colour_MY, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(CE_Colour_CY, COLOR_CYAN, COLOR_YELLOW);

	// Blue background pairs.
	init_pair(CE_Colour_KB, COLOR_BLACK, COLOR_BLUE);
	init_pair(CE_Colour_WB, COLOR_WHITE, COLOR_BLUE);
	init_pair(CE_Colour_RB, COLOR_RED, COLOR_BLUE);
	init_pair(CE_Colour_GB, COLOR_GREEN, COLOR_BLUE);
	init_pair(CE_Colour_YB, COLOR_YELLOW, COLOR_BLUE);
	init_pair(CE_Colour_BB, COLOR_BLUE, COLOR_BLUE);
	init_pair(CE_Colour_MB, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(CE_Colour_CB, COLOR_CYAN, COLOR_BLUE);

	// Magenta background pairs.
	init_pair(CE_Colour_KM, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(CE_Colour_WM, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(CE_Colour_RM, COLOR_RED, COLOR_MAGENTA);
	init_pair(CE_Colour_GM, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(CE_Colour_YM, COLOR_YELLOW, COLOR_MAGENTA);
	init_pair(CE_Colour_BM, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(CE_Colour_MM, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(CE_Colour_CM, COLOR_CYAN, COLOR_MAGENTA);

	// Cyan background pairs.
	init_pair(CE_Colour_KC, COLOR_BLACK, COLOR_CYAN);
	init_pair(CE_Colour_WC, COLOR_WHITE, COLOR_CYAN);
	init_pair(CE_Colour_RC, COLOR_RED, COLOR_CYAN);
	init_pair(CE_Colour_GC, COLOR_GREEN, COLOR_CYAN);
	init_pair(CE_Colour_YC, COLOR_YELLOW, COLOR_CYAN);
	init_pair(CE_Colour_BC, COLOR_BLUE, COLOR_CYAN);
	init_pair(CE_Colour_MC, COLOR_MAGENTA, COLOR_CYAN);
	init_pair(CE_Colour_CC, COLOR_CYAN, COLOR_CYAN);
}

void CCloverEngine::Shutdown()
{
	// Signal that we're no longer running - not really needed, but it's clean.
	m_Running = false;

	// Clear the references to all of the handlers. User responsible for memory.
	m_UpdateHandlers.clear();
	m_KeyHandlers.clear();
	m_MouseHandlers.clear();
	m_DrawHandlers.clear();
	m_WindowHandlers.clear();

	// Shut down curses windows.
	endwin();

	// Delete the game that we were running.
	delete m_Game;

	// Delete our singleton.
	delete m_Instance;
}

void CCloverEngine::StopResize()
{
	// Get the output handle.
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Get the current window info.
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hStdOut, &bufferInfo);

	// No need to resize if we're running fullscreen.
	if (!CE_FULLSCREEN)
	{
		// Is the size of the window not what we set it to?
		if (bufferInfo.dwSize.X != CE_SCREEN_WIDTH || bufferInfo.dwSize.Y != CE_SCREEN_HEIGHT)
		{
			SMALL_RECT windowSize;
			COORD bufferSize;

			// Reset the buffer size.
			bufferSize.X = CE_SCREEN_WIDTH;
			bufferSize.Y = CE_SCREEN_HEIGHT;
			SetConsoleScreenBufferSize(hStdOut, bufferSize);

			// Reset the window size.
			windowSize.Left = 0;
			windowSize.Top = 0;
			windowSize.Right = CE_SCREEN_WIDTH - 1;
			windowSize.Bottom = CE_SCREEN_HEIGHT - 1;
			SetConsoleWindowInfo(hStdOut, TRUE, &windowSize);

			// Clear all windows
			clear();
			for (auto handler : m_WindowHandlers)
			{
				handler->Clear();
			}
		}
	}
}

void CCloverEngine::Update(const double& aDeltaTime)
{
	// Save this frame's delta time. Used for debug display.
	m_DeltaTime = aDeltaTime;

	// Push update event to update handlers.
	for (auto handler : m_UpdateHandlers)
	{
		handler->Update(aDeltaTime);
	}
}

void CCloverEngine::MouseEvent(const SMouseInfo& aEvent)
{
	// Save the mouse event. Used for debug display.
	m_LastMouseEvent = aEvent;

	// Push mouse event to mouse handlers.
	for (auto handler : m_MouseHandlers)
	{
		handler->MouseEvent(aEvent);
	}
}

void CCloverEngine::KeyboardEvent(const SKeyInfo& aEvent)
{
	// Save the key event. Used for debug display.
	m_LastKeyboardEvent = aEvent;

	// Push key event to key handlers.
	for (auto handler : m_KeyHandlers)
	{
		handler->KeyboardEvent(aEvent);
	}

	// Global shutdown key.
	if (CE_SHUTDOWN_KEY && aEvent == CE_SHUTDOWN_KEY)
		Quit();
}

void CCloverEngine::Draw()
{
	// Erase all registered window handlers.
	for (auto handler : m_WindowHandlers)
	{
		handler->Erase();
	}
	
	// Draw all registered draw handlers.
	for (auto handler : m_DrawHandlers)
	{
		handler->Draw();
	}

	// Render all registered window handlers.
	for (auto handler : m_WindowHandlers)
	{
		handler->Render();
	}
}

// Add an update handler to the engine.
void CCloverEngine::RegisterUpdateHandler(CUpdateHandler* aHandler)
{
	// Make sure the handler is valid
	if (aHandler == nullptr)
	{
		return;
	}

	// Make sure we haven't already added this handler
	for (auto handler : m_UpdateHandlers)
	{
		if (handler == aHandler)
		{
			return;
		}
	}
	
	// Add the handler to the list
	m_UpdateHandlers.push_back(aHandler);
}

// Add an update handler to the engine.
void CCloverEngine::RegisterMouseHandler(CMouseHandler* aHandler)
{
	// Make sure the handler is valid
	if (aHandler == nullptr)
	{
		return;
	}

	// Make sure we haven't already added this handler
	for (auto handler : m_MouseHandlers)
	{
		if (handler == aHandler)
		{
			return;
		}
	}

	// Add the handler to the list
	m_MouseHandlers.push_back(aHandler);
}

// Add an update handler to the engine.
void CCloverEngine::RegisterKeyHandler(CKeyHandler* aHandler)
{
	// Make sure the handler is valid
	if (aHandler == nullptr)
	{
		return;
	}

	// Make sure we haven't already added this handler
	for (auto handler : m_KeyHandlers)
	{
		if (handler == aHandler)
		{
			return;
		}
	}

	// Add the handler to the list
	m_KeyHandlers.push_back(aHandler);
}

// Add an update handler to the engine.
void CCloverEngine::RegisterDrawHandler(CDrawHandler* aHandler)
{
	// Make sure the handler is valid
	if (aHandler == nullptr)
	{
		return;
	}

	// Make sure we haven't already added this handler
	for (auto handler : m_DrawHandlers)
	{
		if (handler == aHandler)
		{
			return;
		}
	}

	// Add the handler to the list
	m_DrawHandlers.push_back(aHandler);
}

// Add a window handler to the engine.
void CCloverEngine::RegisterWindowHandler(CWindowHandler* aHandler)
{
	// Make sure the handler is valid
	if (aHandler == nullptr)
	{
		return;
	}

	// Make sure we haven't already added this handler
	for (auto handler : m_WindowHandlers)
	{
		if (handler == aHandler)
		{
			return;
		}
	}

	// Add the handler to the list
	m_WindowHandlers.push_back(aHandler);
}

// Removes an update handler from the engine.
bool CCloverEngine::RemoveUpdateHandler(CUpdateHandler* aHandler)
{
	// Search through the handler list.
	for (unsigned int i = 0; i < m_UpdateHandlers.size(); i++)
	{
		// If found, remove and notify the caller.
		if (m_UpdateHandlers[i] == aHandler)
		{
			m_UpdateHandlers.erase(m_UpdateHandlers.begin() + i);
			return true;
		}
	}
	// Requested handler wasn't found.
	return false;
}

// Removes a mouse handler from the engine.
bool CCloverEngine::RemoveMouseHandler(CMouseHandler* aHandler)
{
	// Search through the handler list.
	for (unsigned int i = 0; i < m_MouseHandlers.size(); i++)
	{
		// If found, remove and notify the caller.
		if (m_MouseHandlers[i] == aHandler)
		{
			m_MouseHandlers.erase(m_MouseHandlers.begin() + i);
			return true;
		}
	}
	// Requested handler wasn't found.
	return false;
}

// Removes a key handler from the engine.
bool CCloverEngine::RemoveKeyHandler(CKeyHandler* aHandler)
{
	// Search through the handler list.
	for (unsigned int i = 0; i < m_KeyHandlers.size(); i++)
	{
		// If found, remove and notify the caller.
		if (m_KeyHandlers[i] == aHandler)
		{
			m_KeyHandlers.erase(m_KeyHandlers.begin() + i);
			return true;
		}
	}
	// Requested handler wasn't found.
	return false;
}

// Removes a draw handler from the engine.
bool CCloverEngine::RemoveDrawHandler(CDrawHandler* aHandler)
{
	// Search through the handler list.
	for (unsigned int i = 0; i < m_DrawHandlers.size(); i++)
	{
		// If found, remove and notify the caller.
		if (m_DrawHandlers[i] == aHandler)
		{
			m_DrawHandlers.erase(m_DrawHandlers.begin() + i);
			return true;
		}
	}
	// Requested handler wasn't found.
	return false;
}

// Removes a window handler from the engine.
bool CCloverEngine::RemoveWindowHandler(CWindowHandler* aHandler)
{
	// Search through the handler list.
	for (unsigned int i = 0; i < m_WindowHandlers.size(); i++)
	{
		// If found, remove and notify the caller.
		if (m_WindowHandlers[i] == aHandler)
		{
			m_WindowHandlers.erase(m_WindowHandlers.begin() + i);
			return true;
		}
	}
	// Requested handler wasn't found.
	return false;
}