/*
VirtualWindow

Manages a virtual windows within the main console window.

Creator:	Charlotte C. Brown
File Date:	October 11th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __VIRTUALWINDOW_H
#define __VIRTUALWINDOW_H

#include "Source\Handler\WindowHandler.h"
#include "Source\Handler\UpdateHandler.h"
#include "Source\IO\Colours.h"
#include "PDCurses\Include\curses.h"
#include <string>

namespace CloverEngine
{
	class CShader;

	/*
	Virtual windows define an area within the main console display to render things
	to the screen. Virtual windows can be used to easily set up screen layouts, pop-
	up windows, etc.
	*/
	class CVirtualWindow : public CWindowHandler
	{
	private:
		// X coordinate of the top-left corner.
		int m_X;

		// Y coordinate of the top-left corner.
		int m_Y;

		// Width of the window.
		unsigned int m_Width;

		// Height of the window.
		unsigned int m_Height;

		// Should the window currently be drawn?
		bool m_Enabled;

		// Pointer to the PDCurses window.
		WINDOW* m_Window;

		// The name of this window, purely for the user's reference.
		std::string m_Name;

		// The shader being used by this window.
		CShader* m_Shader;

	public:

		// Setting the Width or Height to 0 will default to the console window's size.
		CVirtualWindow(std::string aName = "", int aX = 0, int aY = 0, unsigned int aWidth = 0, unsigned int aHeight = 0, bool aEnabled = true);
		virtual ~CVirtualWindow();

		// This is where any logic related to drawing the window takes place, such as shaders.
		virtual void Render();

		// Empties the window's internal buffer.
		virtual void Erase();

		// Empties and completely clears the window's current state. Causes flickering when called.
		virtual void Clear();

		// Gets the reference to the PDCurses window to send things to draw to.
		WINDOW* GetWindow() const { return m_Window; }

		// Gets the width of this window.
		unsigned int GetWidth() const { return m_Width; }

		// Gets the height of this window.
		unsigned int GetHeight() const { return m_Height; }

		// Tells this window to use a given shader.
		void UseShader(CShader* aShader);

		// Stops using whatever shader the window was using, then returns a pointer to it.
		CShader* RemoveShader();

		// Sets the default window colour to the given colour pair.
		void SetBackgroundColour(EColours aColour);
	};
}

#endif