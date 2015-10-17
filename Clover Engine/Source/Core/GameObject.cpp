/*
GameObject

The base object for everything within the game world.

Creator:	Charlotte C. Brown
File Date:	October 16th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "CloverEngine.h"

using namespace CloverEngine;

CGameObject::CGameObject() : m_Transform(nullptr), m_DrawBuffer(nullptr)
{
	// Initialize this object's transform and draw buffer.
	m_Transform = new CTransform(this);
	m_DrawBuffer = new CDrawBuffer(this);

	// Add the components to the list.
	m_Components.reserve(2);
	m_Components.push_back(m_Transform);
	m_Components.push_back(m_DrawBuffer);
}

CGameObject::~CGameObject()
{
	// Delete all of the components that we own.
	for (auto component : m_Components)
	{
		delete component;
	}
	m_Components.clear();

	// No need to delete the two individual pointers, already handled by the vector.
}