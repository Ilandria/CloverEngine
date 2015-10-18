/*
Drawable

Any component that wishes to be drawn to the screen needs to extend this

Creator:	Charlotte C. Brown
File Date:	October 18th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __DRAWABLE_H
#define __DRAWABLE_H

#include "Source\Component\Component.h"
#include "PDCurses\Include\curses.h"
#include "Source\Math\MathTypes.h"

namespace CloverEngine
{
	/*
	This is the base class for any component that is to be drawn to the screen. Draw info is stored
	in a temporary and invisible buffer that is taken by scenes cameras and drawn on the window. Make
	sure you properly override IsType to return true for Drawable and any other types your child
	class is. The default buffer size is 1x1 (a single char), so be sure to call NewBuffer() if that
	is not the size you wish to have.
	*/
	class CDrawable : public CComponent
	{
	private:
		// This DrawBuffer's buffer window.
		WINDOW* m_Buffer;

		// The buffer's current width and height.
		SVector2<int> m_Size;

	public:
		// All components know who their owner is.
		CDrawable(CGameObject* aOwner);

		// Kill things here if things need to be killed.
		virtual ~CDrawable();

		/*
		For any component you create, override this method and make it return true for every type
		of component that it is.
		*/
		virtual bool IsType(const int& aType) const;

		// Clears the buffer and sets its size.
		void NewBuffer(const int& aWidth, const int& aHeight);

		// Gets the buffer's draw window, width, and height.
		void GetDrawInfo(WINDOW* aWindow, int* aWidth, int* aHeight);

		// Erases the buffer's contents, does not delete or resize the buffer.
		void Erase();
	};
}

#endif