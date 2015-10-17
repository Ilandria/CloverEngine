/*
Shader

If enabled, shaders manipulate a VirtualWindow's final display to make pretty things.

Creator:	Charlotte C. Brown
File Date:	October 11th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __SHADER_H
#define __SHADER_H

namespace CloverEngine
{
	struct SCharInfo;
	class CVirtualWindow;

	/*
	Extend this class and implement the run method to be able to pass it into a VirtualWindow
	in order to affect that window's final output. The shader runs after all game operations and
	doesn't affect any data - it's purely for visuals. You'll have to dig in to CloverEngine::SCharInfo,
	CloverEngine::EColors well as PDCurses to see exactly what kind of effects one can create. Really,
	it's only limited by your imagination and math powers. Oh... and the fact that we're in a console
	window, that too...
	*/
	class CShader
	{
	public:
		virtual ~CShader() { }

		/*
		Called once for each "pixel" of the final display in the window that is running the shader. If
		you find you're getting entirely empty screens, make sure you're not accidentally printing spaces
		or empty chars over top of things (check SCharInfo.m_Key == 32, for example).

		Params:
		- aChar : The character and all of its info passed from the VirtualWindow.
		*/
		virtual void Run(SCharInfo& aChar, const unsigned int& aWidth, const unsigned int& aHeight) = 0;
	};
}

#endif