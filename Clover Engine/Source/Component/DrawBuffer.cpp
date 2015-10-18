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

CDrawBuffer::CDrawBuffer(CGameObject* aOwner) : CComponent(aOwner), m_Buffer(nullptr)
{
	// Initialize the size.
	m_Size.m_X = 1;
	m_Size.m_Y = 1;

	// Get this component's owner's transform component.
	CTransform* ownerTransform = m_Owner->GetTransform();

	// Save the size to this buffer.
	m_Size.m_X = (int)ownerTransform->GetWidth();
	m_Size.m_Y = (int)ownerTransform->GetHeight();

	// Create the buffer equal to the size of the owner.
	m_Buffer = newwin(m_Size.m_Y, m_Size.m_X, 0, 0);
}

CDrawBuffer::~CDrawBuffer()
{
	// Clear the buffer and delete it.
	wclear(m_Buffer);
	delwin(m_Buffer);
}

bool CDrawBuffer::IsType(const int& aType) const
{
	return aType == CE_ComponentType_DrawBuffer;
}

void CDrawBuffer::RefreshBuffer()
{
	// Clear and delete the previous buffer.
	wclear(m_Buffer);
	delwin(m_Buffer);
	m_Buffer = nullptr;

	// Get this component's owner's transform component.
	CTransform* ownerTransform = m_Owner->GetTransform();

	// Save the size to this buffer.
	m_Size.m_X = (int)ownerTransform->GetWidth();
	m_Size.m_Y = (int)ownerTransform->GetHeight();

	// Create the buffer equal to the size of the owner.
	m_Buffer = newwin(m_Size.m_Y, m_Size.m_X, 0, 0);
}

void CDrawBuffer::GetBufferInfo(WINDOW* aWindow, int* aWidth, int* aHeight)
{
	aWindow = m_Buffer;
	*aWidth = m_Size.m_X;
	*aHeight = m_Size.m_Y;
}