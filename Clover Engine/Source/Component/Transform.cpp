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

/*
For any component you create, override this method and make it return true for every type
of component that it is.
*/
bool CTransform::IsType(const int& aType) const
{ 
	return aType == CE_ComponentType_Transform;
}

// Get the current x position.
double CTransform::GetX() const
{ 
	return m_Position->m_X; 
}

// Get the current y position.
double CTransform::GetY() const
{
	return m_Position->m_Y; 
}

// Get the current position.
const SVector2<double>* CTransform::GetPosition() const
{ 
	return m_Position;
}

// Get the current width.
double CTransform::GetWidth() const 
{
	return m_Size->m_X; 
}

// Get the current height.
double CTransform::GetHeight() const 
{ 
	return m_Size->m_Y; 
}

// Get the current size.
const SVector2<double>* CTransform::GetSize() const 
{
	return m_Size; 
}

// Set the current x position.
void CTransform::SetX(const double& aX)
{
	m_Position->m_X = aX; 
}

// Set the current y position.
void CTransform::SetY(const double& aY)
{
	m_Position->m_Y = aY; 
}

// Set the current position.
void CTransform::SetPosition(const double& aX, const double& aY) 
{ 
	m_Position->m_X = aX; 
	m_Position->m_Y = aY;
}

// Set the current position.
void CTransform::SetPosition(const SVector2<double>& aPosition)
{
	m_Position->m_X = aPosition.m_X; 
	m_Position->m_Y = aPosition.m_Y;
}

// Set the current width.
void CTransform::SetWidth(const double& aWidth) 
{
	m_Size->m_X = aWidth;
}

// Set the current height.
void CTransform::SetHeight(const double& aHeight)
{ 
	m_Size->m_Y = aHeight;
}

// Set the current size.
void CTransform::SetSize(const double& aWidth, const double& aHeight)
{
	m_Size->m_X = aWidth;
	m_Size->m_Y = aHeight;
}

// Set the current size.
void CTransform::SetSize(const SVector2<double>& aSize) 
{
	m_Size->m_X = aSize.m_X; 
	m_Size->m_Y = aSize.m_Y; 
}

// Move horizontally relative to the current x position.
void CTransform::MoveX(const double& aDistance) 
{
	m_Position->m_X += aDistance;
}

// Move vertically relative to the current y position.
void CTransform::MoveY(const double& aDistance)
{
	m_Position->m_Y += aDistance;
}

// Move relative to the current position.
void CTransform::Move(const double& aDistanceX, const double& aDistanceY)
{ 
	m_Position->m_X += aDistanceX; 
	m_Position->m_Y += aDistanceY;
}

// Move relative to the current position.
void CTransform::Move(const SVector2<double>& aDistance)
{ 
	m_Position->m_X += aDistance.m_X; 
	m_Position->m_Y += aDistance.m_Y;
}