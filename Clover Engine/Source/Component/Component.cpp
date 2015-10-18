/*
Component

Anything intended to add functionality to a GameObject is added via a component.

Creator:	Charlotte C. Brown
File Date:	October 17th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace std;
using namespace CloverEngine;

CComponent::CComponent(CGameObject* aOwner) : m_Owner(aOwner)
{
	// Initialize this component's name.
	m_Name = "";
}

CComponent::~CComponent()
{
}

bool CComponent::IsType(const int& aType) const
{
	return aType == CE_ComponentType_Invalid;
}

void CComponent::SetName(const string& aName)
{
	m_Name = aName;
}

string CComponent::GetName() const
{
	return m_Name;
}