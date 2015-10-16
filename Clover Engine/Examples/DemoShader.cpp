/*
DemoShader

Example of how to set up a shader.

Creator:	Charlotte C. Brown
File Date:	October 11th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"
#include "DemoShader.h"

using namespace std;
using namespace CloverEngine;

void CDemoShader::Run(SCharInfo& aChar, const unsigned int& aWidth, const unsigned int& aHeight)
{
	// Do pretty things here.
	aChar.m_X = (int)round(aChar.m_X * 0.5f + aWidth / 4.0f);
	aChar.m_Y = (int)round(aChar.m_Y * 0.5f + aHeight / 4.0f);
}