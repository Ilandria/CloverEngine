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
		SVector2<double> m_Position;
		SVector2<double> m_Size;

	public:
		// All components know who their owner is.
		CTransform(CGameObject* aOwner);

		// Kill things here if things need to be killed.
		virtual ~CTransform();

		/*
		For any component you create, override this method and make it return true for every type
		of component that it is.
		*/
		virtual bool IsType(const int& aType) const;

		// Get the current x position.
		double GetX() const;

		// Get the current y position.
		double GetY() const;

		// Get the current position.
		const SVector2<double> GetPosition() const;

		// Get the current width.
		double GetWidth() const;

		// Get the current height.
		double GetHeight() const;

		// Get the current size.
		const SVector2<double> GetSize() const;

		// Set the current x position.
		void SetX(const double& aX);

		// Set the current y position.
		void SetY(const double& aY);

		// Set the current position.
		void SetPosition(const double& aX, const double& aY);

		// Set the current position.
		void SetPosition(const SVector2<double>& aPosition);

		// Set the current width.
		void SetWidth(const double& aWidth);

		// Set the current height.
		void SetHeight(const double& aHeight);

		// Set the current size.
		void SetSize(const double& aWidth, const double& aHeight);

		// Set the current size.
		void SetSize(const SVector2<double>& aSize);

		// Move horizontally relative to the current x position.
		void MoveX(const double& aDistance);

		// Move vertically relative to the current y position.
		void MoveY(const double& aDistance);

		// Move relative to the current position.
		void Move(const double& aDistanceX, const double& aDistanceY);

		// Move relative to the current position.
		void Move(const SVector2<double>& aDistance);
	};
}

#endif