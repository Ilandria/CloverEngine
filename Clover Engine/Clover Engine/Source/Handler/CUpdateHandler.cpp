/*
UpdateHandler

Interface to be implemented by anything that wants to receive update events.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace std;
using namespace CloverEngine;

CUpdateHandler::CUpdateHandler()
{
	CCloverEngine::GetInstance()->RegisterUpdateHandler(this);
}

CUpdateHandler::~CUpdateHandler()
{
	CCloverEngine::GetInstance()->RemoveUpdateHandler(this);
}