/*
GameObject

The base object for everything within the game world.

Creator:	Charlotte C. Brown
File Date:	October 16th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "CloverEngine.h"

using namespace std;
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

CTransform* CGameObject::GetTransform()
{
	return m_Transform;
}

CComponent* CGameObject::AddComponent(CComponent* aComponent)
{
	// Is the given component a null pointer?
	if (aComponent != nullptr)
	{
		// Is the given component valid?
		if (!aComponent->IsType(CE_ComponentType_Invalid) && !aComponent->IsType(CE_ComponentType_Transform))
		{
			// Add the component.
			m_Components.push_back(aComponent);

			// Return the component (for chaining purposes).
			return aComponent;
		}
	}

	// Not valid - return a null pointer.
	return nullptr;
}

CComponent* CGameObject::GetComponent(const int& aType)
{
	// Search through the components.
	for (auto component : m_Components)
	{
		// If we found the correct one...
		if (component->IsType(aType))
		{
			// Return it.
			return component;
		}
	}

	// No requested component found.
	return nullptr;
}

CComponent* CGameObject::GetComponent(const string& aName)
{
	// Search through the components.
	for (auto component : m_Components)
	{
		// If we found the correct one...
		if (component->GetName() == aName)
		{
			// Return it.
			return component;
		}
	}

	// No requested component found.
	return nullptr;
}

vector<CComponent*> CGameObject::GetComponents()
{
	return m_Components;
}

vector<CComponent*> CGameObject::GetComponents(const int& aType)
{
	// Make the list of components that we've found.
	vector<CComponent*> components = {};

	// Search through the components.
	for (auto component : m_Components)
	{
		// If we found a matching one...
		if (component->IsType(aType))
		{
			// Add it to the vector.
			components.push_back(component);
		}
	}

	// Return the vector.
	return components;
}

vector<CComponent*> CGameObject::GetComponents(const string& aName)
{
	// Make the list of components that we've found.
	vector<CComponent*> components = {};

	// Search through the components.
	for (auto component : m_Components)
	{
		// If we found a matching one...
		if (component->GetName() == aName)
		{
			// Add it to the vector.
			components.push_back(component);
		}
	}

	// Return the vector.
	return components;
}