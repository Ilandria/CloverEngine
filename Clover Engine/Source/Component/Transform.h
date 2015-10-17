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

#include "Source\Component\Component.h"

namespace CloverEngine
{
	class CTransform : public CComponent
	{
	private:
		// TODO: Implement Transform.

	public:
		// All components know who their owner is.
		CTransform(CGameObject* aOwner) : CComponent(aOwner) { }

		// Kill things here if things need to be killed.
		virtual ~CTransform() { }

		/*
		For any component you create, override this method and make it return true for every type
		of component that it is.
		*/
		virtual bool IsType(const int& aType) const { return aType == CE_ComponentType_Transform; }
	};
}

#endif