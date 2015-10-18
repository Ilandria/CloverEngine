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

CGameObject::CGameObject() : m_Transform(nullptr)
{
	// Initialize this object's transform and draw buffer.
	m_Transform = new CTransform(this);

	// Add the components to the list.
	m_Components.push_back(m_Transform);
}

CGameObject::~CGameObject()
{
	// Delete all of the components that we own.
	for (auto component : m_Components)
	{
		delete component;
	}
	m_Components.clear();

	/* No need to delete the two individual pointers, already handled by the vector
	and we're about to fall out of scope so no nullptr is needed. */
}