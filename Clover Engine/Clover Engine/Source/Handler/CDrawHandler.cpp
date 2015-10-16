/*
DrawHandler

Interface to be implemented by anything that wants to draw itself on the screen.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace std;
using namespace CloverEngine;

CDrawHandler::CDrawHandler()
{
	CCloverEngine::GetInstance()->RegisterDrawHandler(this);
}

CDrawHandler::~CDrawHandler()
{
	CCloverEngine::GetInstance()->RemoveDrawHandler(this);
}