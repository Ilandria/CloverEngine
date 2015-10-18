/*
DrawBuffer

Component that stores information to be drawn to the screen at a later time.

Creator:	Charlotte C. Brown
File Date:	October 16th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __DRAWBUFFER_H
#define __DRAWBUFFER_H

#include "Source\Component\Component.h"

namespace CloverEngine
{
	/*
	A GameObject, Sprite, Camera, etc.'s display is stored in a DrawBuffer prior to being rendered
	on the actual console window. This allows for easily pushing around and manipulating the
	final image without having to direct access any classes.
	*/
	class CDrawBuffer : public CComponent
	{
	private:
		// TODO: Implement DrawBuffer.

	public:
		// All components know who their owner is.
		CDrawBuffer(CGameObject* aOwner);

		// Kill things here if things need to be killed.
		virtual ~CDrawBuffer();

		/*
		For any component you create, override this method and make it return true for every type
		of component that it is.
		*/
		virtual bool IsType(const int& aType) const;
	};
}

#endif