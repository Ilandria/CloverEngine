/*
Transform

Component that tracks a GameObject's position and size.

Creator:	Charlotte C. Brown
File Date:	October 16th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#include "Source\Core\CloverEngine.h"

using namespace CloverEngine;

// All components know who their owner is.
CTransform::CTransform(CGameObject* aOwner) : CComponent(aOwner), m_Position(nullptr), m_Size(nullptr)
{
	m_Position = new SVector2<double>();
	m_Size = new SVector2<double>();
}

// Kill things here if things need to be killed.
CTransform::~CTransform()
{
	delete m_Position;
	delete m_Size;
}