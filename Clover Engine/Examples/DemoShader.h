/*
DemoShader

Example of how to set up a shader.

Creator:	Charlotte C. Brown
File Date:	October 11th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __DEMOSHADER_H
#define __DEMOSHADER_H

#include "PDCurses\Include\curses.h"

namespace CloverEngine
{
	struct SCharInfo;

	// See Shader.h for information on exactly how this works. This is a demo class for implementation.
	class CDemoShader : public CShader
	{
	public:
		void Run(SCharInfo& aChar, const unsigned int& aWidth, const unsigned int& aHeight);
	};
}

#endif