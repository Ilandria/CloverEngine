/*
DrawBuffer

Component that stores information to be drawn to the screen at a later time.

Creator:	Charlotte C. Brown
File Date:	October 18th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace CloverEngine;

CDrawBuffer::CDrawBuffer(CGameObject* aOwner) : CComponent(aOwner)
{
}

CDrawBuffer::~CDrawBuffer()
{
}

bool CDrawBuffer::IsType(const int& aType) const
{
	return aType == CE_ComponentType_DrawBuffer;
}