/*
Transform

Component that tracks a GameObject's position and size.

Creator:	Charlotte C. Brown
File Date:	October 16th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __TRANSFORM_H
#define __TRANSFORM_H

#include "Source\Math\MathTypes.h"
#include "Source\Component\Component.h"

namespace CloverEngine
{
	/*
	Transform is responsible for tracking the position and size of a GameObject. These values are
	tracked as doubles to allow for fluid movement, but they will always be rounded to the nearest
	integral value whenever being drawn to the console window - so be weary of that!
	*/
	class CTransform : public CComponent
	{
	private:
		// Current x position.
		SVector2<double>* m_Position;
		SVector2<double>* m_Size;

	public:
		// All components know who their owner is.
		CTransform(CGameObject* aOwner);

		// Kill things here if things need to be killed.
		virtual ~CTransform();

		/*
		For any component you create, override this method and make it return true for every type
		of component that it is.
		*/
		virtual bool IsType(const int& aType) const { return aType == CE_ComponentType_Transform; }

		// Get the current x position.
		double GetX() const { return m_Position->m_X; }

		// Get the current y position.
		double GetY() const { return m_Position->m_Y; }

		// Get the current position.
		const SVector2<double>* GetPosition() const { return m_Position; }

		// Get the current width.
		double GetWidth() const { return m_Size->m_X; }

		// Get the current height.
		double GetHeight() const { return m_Size->m_Y; }

		// Get the current size.
		const SVector2<double>* GetSize() const { return m_Size; }

		// Set the current x position.
		void SetX(const double& aX) { m_Position->m_X = aX; }

		// Set the current y position.
		void SetY(const double& aY) { m_Position->m_Y = aY; }

		// Set the current position.
		void SetPosition(const double& aX, const double& aY) { m_Position->m_X = aX; m_Position->m_Y = aY; }

		// Set the current position.
		void SetPosition(const SVector2<double>& aPosition) { m_Position->m_X = aPosition.m_X; m_Position->m_Y = aPosition.m_Y; }

		// Set the current width.
		void SetWidth(const double& aWidth) { m_Size->m_X = aWidth; }

		// Set the current height.
		void SetHeight(const double& aHeight) { m_Size->m_Y = aHeight; }

		// Set the current size.
		void SetSize(const double& aWidth, const double& aHeight) { m_Size->m_X = aWidth; m_Size->m_Y = aHeight; }

		// Set the current size.
		void SetSize(const SVector2<double>& aSize) { m_Size->m_X = aSize.m_X; m_Size->m_Y = aSize.m_Y; }

		// Move horizontally relative to the current x position.
		void MoveX(const double& aDistance) { m_Position->m_X += aDistance; }

		// Move vertically relative to the current y position.
		void MoveY(const double& aDistance) { m_Position->m_Y += aDistance; }

		// Move relative to the current position.
		void Move(const double& aDistanceX, const double& aDistanceY) { m_Position->m_X += aDistanceX; m_Position->m_Y += aDistanceY; }

		// Move relative to the current position.
		void Move(const SVector2<double>& aDistance) { m_Position->m_X += aDistance.m_X; m_Position->m_Y += aDistance.m_Y; }
	};
}

#endif