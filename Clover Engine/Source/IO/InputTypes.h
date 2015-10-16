/*
InputTypes

This header file contains the definitions of the data packages that are used to send
controller input data around the game engine.

Creator:	Charlotte C. Brown
File Date:	October 4th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __INPUTTYPES_H
#define __INPUTTYPES_H

namespace CloverEngine
{
	/*
	Tracks information about a keypress. Look up Virtual-Key Codes and KEY_EVENT_RECORD for
	information on how to properly check for flags and set values.
	*/
	struct SKeyInfo
	{
		// False = key was released, true = key was pressed.
		bool m_Pressed = false;

		// Which key is being pressed.
		unsigned short m_Key = 0;

		// Which modifier keys are on.
		unsigned int m_Modifier = 0;

		// Used for checking if just the key code is equal to another key code.
		inline bool operator== (const unsigned short& aKeyCode) const { return m_Key == aKeyCode; }

		// Used for checking if everything about this key is equal to another.
		inline bool operator== (const SKeyInfo& aKeyInfo) const
		{
			return m_Key == aKeyInfo.m_Key && aKeyInfo.m_Modifier && m_Pressed == aKeyInfo.m_Pressed;
		}
	};

	/*
	Tracks information about the mouse. Look up MOUSE_EVENT_RECORD information on how to
	properly check for flags and set values.
	*/
	struct SMouseInfo
	{
		// The X location of the mouse on the window
		unsigned short m_X = 0;

		// The Y location of the mouse on the window
		unsigned short m_Y = 0;

		// Which button is being pressed. (See MOUSE_EVENT_RECORD)
		unsigned int m_Button = 0;

		// Which modifier keys are on. (Shift, ctrl, alt, etc.)
		unsigned int m_Modifier = 0;

		// What state the mouse is currently in. (Double click, mouse moved, etc.)
		unsigned int m_Event = 0;

		// Used for checking if the mouse action is equal to another mouse action. Doesn't care about coordinates.
		inline bool operator== (const SMouseInfo& aMouseInfo) const
		{
			return m_Button == aMouseInfo.m_Button && m_Modifier == aMouseInfo.m_Modifier && m_Event == aMouseInfo.m_Event;
		}
	};

	/*
	Tracks information about a given character/"pixel". Used primarily by the rendering
	pipeline for easy calculation of shader stuffs.
	*/
	struct SCharInfo
	{
		// The actual character value.
		unsigned short m_Char = 0;

		// The x position of the character.
		int m_X = 0;

		// The y position of the character.
		int m_Y = 0;

		// The colour pair index.
		unsigned char m_Colour = 0;

		// Is the character bold?
		bool m_Bold = false;

		// Is the character colouring reversed?
		bool m_Reverse = false;

		// Is the character blinking?
		bool m_Blink = false;

		// Is this an alternate character?
		bool m_AltChar = false;
	};
}

#endif