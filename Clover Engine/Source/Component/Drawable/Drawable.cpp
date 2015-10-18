/*
Drawable

Any component that wishes to be drawn to the screen needs to extend this

Creator:	Charlotte C. Brown
File Date:	October 18th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace CloverEngine;

CDrawable::CDrawable(CGameObject* aOwner) : CComponent(aOwner), m_Buffer(nullptr)
{
	// Initialize the size.
	m_Size.m_X = 1;
	m_Size.m_Y = 1;

	// Create the default buffer.
	m_Buffer = newwin(m_Size.m_Y, m_Size.m_X, 0, 0);
}

CDrawable::~CDrawable()
{
	// Clear the buffer and delete it.
	werase(m_Buffer);
	delwin(m_Buffer);
}

bool CDrawable::IsType(const int& aType) const
{
	return aType == CE_ComponentType_Drawable;
}

void CDrawable::NewBuffer(const int& aWidth, const int& aHeight)
{
	// Clear and delete the previous buffer.
	werase(m_Buffer);
	delwin(m_Buffer);
	m_Buffer = nullptr;

	// Save the size of this buffer.
	m_Size.m_X = aWidth;
	m_Size.m_Y = aHeight;

	// Create the buffer equal to the size of the owner.
	m_Buffer = newwin(m_Size.m_Y, m_Size.m_X, 0, 0);
}

void CDrawable::GetDrawInfo(WINDOW* aWindow, int* aWidth, int* aHeight)
{
	aWindow = m_Buffer;
	*aWidth = m_Size.m_X;
	*aHeight = m_Size.m_Y;
}

WINDOW* CDrawable::GetPDWindow()
{
	return m_Buffer;
}

void CDrawable::Erase()
{
	werase(m_Buffer);
}