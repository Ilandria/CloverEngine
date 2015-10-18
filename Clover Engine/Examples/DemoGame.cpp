/*
DemoGame

Example of how to set up your own child of CloverGame

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"
#include "Examples\DemoGame.h"
#include "Examples\DemoShader.h"

using namespace std;
using namespace CloverEngine;

CDemoGame::CDemoGame() 
{

}

CDemoGame::~CDemoGame()
{

}

void CDemoGame::InitializeGame()
{
	/* Setting a window to 0, 0, 0, 0 makes it default to the full window. The name is entirely for your own
	reference later, should you want to display it as a title or the like. */
	m_Window = new CVirtualWindow("Demo Window");

	// An example shader.
	m_Shader = new CDemoShader();

	// Tell the window that we want to use this shader.
	m_Window->UseShader(m_Shader);

	// TODO: Delete this
	CGameObject* gameObject = new CGameObject();
	CSimpleSprite* simpleSprite = new CSimpleSprite(gameObject);
	simpleSprite->SetName("Test Sprite");
	simpleSprite->SetSprite(chtype('O' | A_BOLD | COLOR_PAIR(CE_Colour_YK)));
	gameObject->AddComponent(simpleSprite);
}

void CDemoGame::ShutdownGame()
{
	// Clean up the window that we made.
	delete m_Window;

	// Clean up the shader that we made.
	delete m_Shader;
}

void CDemoGame::KeyboardEvent(const CloverEngine::SKeyInfo& aEvent)
{

}

void CDemoGame::MouseEvent(const CloverEngine::SMouseInfo& aEvent)
{

}

void CDemoGame::Update(double aDelta)
{ 

}

void CDemoGame::Draw()
{
	// Get the actual PDCurses window from the VirtualWindow.
	WINDOW* win = m_Window->GetWindow();

	// Draw to the window. This uses PDCurses lingo, so look there for documentation. Look at Colours.h for available colour pairs.
	wattron(win, A_BOLD);
	wattron(win, COLOR_PAIR(CE_Colour_WK));
	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	mvwaddch(win, CCloverEngine::GetInstance()->GetLastMouseEvent().m_Y, CCloverEngine::GetInstance()->GetLastMouseEvent().m_X, ACS_DIAMOND);
	wattroff(win, COLOR_PAIR(CE_Colour_WK));
	wattroff(win, A_BOLD);
}