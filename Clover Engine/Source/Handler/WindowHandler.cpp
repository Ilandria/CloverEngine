/*
WindowHandler

Interface to be implemented by all windows in order to be rendered appropriately

Creator:	Charlotte C. Brown
File Date:	October 11th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace std;
using namespace CloverEngine;

CWindowHandler::CWindowHandler()
{
	CCloverEngine::GetInstance()->RegisterWindowHandler(this);
}

CWindowHandler::~CWindowHandler()
{
	CCloverEngine::GetInstance()->RemoveWindowHandler(this);
}