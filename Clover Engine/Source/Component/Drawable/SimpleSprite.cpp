/*
SimpleSprite

A basic 1 character display

Creator:	Charlotte C. Brown
File Date:	October 18th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace CloverEngine;

CSimpleSprite::CSimpleSprite(CGameObject* aOwner) : CDrawable(aOwner)
{
	// Make the buffer 1x1.
	NewBuffer(1, 1);

	// Draw the default "error" character.
	mvwaddch(GetPDWindow(), 0, 0, chtype('X' | COLOR_PAIR(CE_Colour_CR) | A_BLINK));
}

CSimpleSprite::~CSimpleSprite()
{

}

void CSimpleSprite::SetSprite(chtype aCharacter)
{
	// Clear whatever is currently in the buffer.
	Erase();

	// Add the new character.
	mvwaddch(GetPDWindow(), 0, 0, aCharacter);
}