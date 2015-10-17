/*
VirtualWindow

Manages a virtual windows within the main console window.

Creator:	Charlotte C. Brown
File Date:	October 11th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace std;
using namespace CloverEngine;

CVirtualWindow::CVirtualWindow(string aName, int aX, int aY, unsigned int aWidth, unsigned int aHeight, bool aEnabled) :
	m_Name(aName), m_X(aX), m_Y(aY), m_Width(aWidth), m_Height(aHeight), m_Enabled(aEnabled), m_Shader(nullptr)
{
	// Check if we're setting height to the full console height.
	if (m_Height == 0)
	{
		m_Height = CCloverEngine::GetInstance()->CE_SCREEN_HEIGHT;
	}

	// Check if we're setting width to the full console width.
	if (m_Width == 0)
	{
		m_Width = CCloverEngine::GetInstance()->CE_SCREEN_WIDTH;
	}

	m_Window = newwin(m_Height, m_Width, m_Y, m_X);
}

CVirtualWindow::~CVirtualWindow()
{
	Clear();
	delwin(m_Window);
}

void CVirtualWindow::Render()
{
	if (m_Shader != nullptr)
	{
		// Memory for each pixel.
		SCharInfo** pixels = new SCharInfo*[m_Height];
		for (unsigned int y = 0; y < m_Height; y++)
			pixels[y] = new SCharInfo[m_Width];

		// Read in the display.
		for (unsigned int y = 0; y < m_Height; y++)
		{
			for (unsigned int x = 0; x < m_Width; x++)
			{
				// Grab the current pixel info.
				chtype pixel = mvwinch(m_Window, y, x);

				// Set up the CharInfo to send to the shader.
				SCharInfo charInfo;
				charInfo.m_X = x;
				charInfo.m_Y = y;
				charInfo.m_Char = pixel & A_CHARTEXT;
				charInfo.m_Bold = (pixel & A_BOLD) > 0;
				charInfo.m_Blink = (pixel & A_BLINK) > 0;
				charInfo.m_Reverse = (pixel & A_REVERSE) > 0;
				charInfo.m_AltChar = (pixel & A_ALTCHARSET) > 0;
				while ((pixel & A_COLOR) != COLOR_PAIR(charInfo.m_Colour))
				{
					charInfo.m_Colour++;
					if (charInfo.m_Colour == CE_Colour_Total)
					{
						charInfo.m_Colour = -1;
						break;
					}
				}

				// Send our ugly chars to the shader to be made pretty.
				m_Shader->Run(charInfo, m_Width, m_Height);

				// Save the modified character for future drawing.
				pixels[y][x] = charInfo;
			}
		}

		// Clear the screen.
		Erase();

		// Redraw each pixel with the shader effect applied.
		for (unsigned int y = 0; y < m_Height; y++)
		{
			for (unsigned int x = 0; x < m_Width; x++)
			{
				// The current character to be drawn.
				SCharInfo aChar = pixels[y][x];

				// Draw the final pixel.
				wattron(m_Window, COLOR_PAIR(aChar.m_Colour));
				if (aChar.m_AltChar)
				{
					wattron(m_Window, A_ALTCHARSET);
				}
				if (aChar.m_Blink)
				{
					wattron(m_Window, A_BLINK);
				}
				if (aChar.m_Bold)
				{
					wattron(m_Window, A_BOLD);
				}
				if (aChar.m_Reverse)
				{
					wattron(m_Window, A_REVERSE);
				}

				// 32 = Blank, don't draw those because we don't want to cover things up accidentally.
				if (aChar.m_Char != 32)
					mvwaddch(m_Window, aChar.m_Y, aChar.m_X, aChar.m_Char);

				wattroff(m_Window, COLOR_PAIR(aChar.m_Colour));
				if (aChar.m_AltChar)
				{
					wattroff(m_Window, A_ALTCHARSET);
				}
				if (aChar.m_Blink)
				{
					wattroff(m_Window, A_BLINK);
				}
				if (aChar.m_Bold)
				{
					wattroff(m_Window, A_BOLD);
				}
				if (aChar.m_Reverse)
				{
					wattroff(m_Window, A_REVERSE);
				}
			}
		}

		// Free the previously allocated memory.
		for (unsigned int y = 0; y < m_Height; y++)
			delete[] pixels[y];
		delete[] pixels;
	}

	wrefresh(m_Window);
}

void CVirtualWindow::Erase()
{
	werase(m_Window);
}

void CVirtualWindow::Clear()
{
	wclear(m_Window);
}

void CVirtualWindow::UseShader(CShader* aShader)
{
	if (aShader != nullptr)
	{
		m_Shader = aShader;
	}
}

CShader* CVirtualWindow::RemoveShader()
{
	CShader* previousShader = m_Shader;
	m_Shader = nullptr;
	return previousShader;
}