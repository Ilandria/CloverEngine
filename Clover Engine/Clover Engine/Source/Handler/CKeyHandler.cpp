/*
KeyHandler

Interface to be implemented by anything that wants to receive key events.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace std;
using namespace CloverEngine;

CKeyHandler::CKeyHandler()
{
	CCloverEngine::GetInstance()->RegisterKeyHandler(this);
}

CKeyHandler::~CKeyHandler()
{
	CCloverEngine::GetInstance()->RemoveKeyHandler(this);
}