/*
SimpleSprite

A basic 1 character display

Creator:	Charlotte C. Brown
File Date:	October 18th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __SIMPLESPRITE_H
#define __SIMPLESPRITE_H

#include "Drawable.h"

namespace CloverEngine
{
	class CSimpleSprite : public CDrawable
	{
	private:


	public:
		// All components know who their owner is.
		CSimpleSprite(CGameObject* aOwner);

		// Kill things here if things need to be killed.
		virtual ~CSimpleSprite();

		// Sets the sprite's display.
		virtual void SetSprite(chtype aCharacter);
	};
}

#endif