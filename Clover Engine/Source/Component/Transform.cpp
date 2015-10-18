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

CTransform::CTransform(CGameObject* aOwner) : CComponent(aOwner), m_Position(nullptr), m_Size(nullptr)
{
	m_Position = new SVector2<double>();
	m_Size = new SVector2<double>();
}

CTransform::~CTransform()
{
	delete m_Position;
	delete m_Size;
}

bool CTransform::IsType(const int& aType) const
{ 
	return aType == CE_ComponentType_Transform;
}

double CTransform::GetX() const
{ 
	return m_Position->m_X; 
}

double CTransform::GetY() const
{
	return m_Position->m_Y; 
}

const SVector2<double>* CTransform::GetPosition() const
{
	return m_Position;
}

double CTransform::GetWidth() const 
{
	return m_Size->m_X; 
}

double CTransform::GetHeight() const 
{ 
	return m_Size->m_Y; 
}

const SVector2<double>* CTransform::GetSize() const 
{
	return m_Size; 
}

void CTransform::SetX(const double& aX)
{
	m_Position->m_X = aX; 
}

void CTransform::SetY(const double& aY)
{
	m_Position->m_Y = aY; 
}

void CTransform::SetPosition(const double& aX, const double& aY) 
{ 
	m_Position->m_X = aX; 
	m_Position->m_Y = aY;
}

void CTransform::SetPosition(const SVector2<double>& aPosition)
{
	m_Position->m_X = aPosition.m_X; 
	m_Position->m_Y = aPosition.m_Y;
}

void CTransform::SetWidth(const double& aWidth) 
{
	m_Size->m_X = aWidth;
}

void CTransform::SetHeight(const double& aHeight)
{ 
	m_Size->m_Y = aHeight;
}

void CTransform::SetSize(const double& aWidth, const double& aHeight)
{
	m_Size->m_X = aWidth;
	m_Size->m_Y = aHeight;
}

void CTransform::SetSize(const SVector2<double>& aSize) 
{
	m_Size->m_X = aSize.m_X; 
	m_Size->m_Y = aSize.m_Y; 
}

void CTransform::MoveX(const double& aDistance) 
{
	m_Position->m_X += aDistance;
}

void CTransform::MoveY(const double& aDistance)
{
	m_Position->m_Y += aDistance;
}

void CTransform::Move(const double& aDistanceX, const double& aDistanceY)
{ 
	m_Position->m_X += aDistanceX; 
	m_Position->m_Y += aDistanceY;
}

void CTransform::Move(const SVector2<double>& aDistance)
{ 
	m_Position->m_X += aDistance.m_X; 
	m_Position->m_Y += aDistance.m_Y;
}