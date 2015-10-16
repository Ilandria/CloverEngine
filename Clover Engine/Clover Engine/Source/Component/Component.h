/*
Component

Anything intended to add functionality to a GameObject is added via a component.

Creator:	Charlotte C. Brown
File Date:	October 16th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __COMPONENT_H
#define __COMPONENT_H

namespace CloverEngine
{
	// What kind of component this is. Used for object type casting. Make sure you're right!
	enum EComponentTypes
	{
		CE_ComponentType_Invalid = 0,
		CE_ComponentType_UpdateHandler,
		CE_ComponentType_KeyHandler,
		CE_ComponentType_MouseHandler,
		CE_ComponentType_DrawHandler,
		CE_ComponentType_DrawBuffer,
		CE_ComponentType_Script
	};

	// Forward declarations.
	class CGameObject;

	/*
	Components can be almost anything imaginable. If you wish to add functionality to a GameObject,
	you must either use a pre-made component or create your own component and add an instance of it
	to said GameObject. The base component has almost no functionality beyond simply tracking what
	kind of component it is.
	*/
	class CComponent
	{
	protected:
		// The object that owns this one.
		CGameObject* m_Owner;

	public:
		// All components know who their owner is.
		CComponent(CGameObject* aOwner) : m_Owner(aOwner) { }

		// Kill things here if things need to be killed.
		virtual ~CComponent() { }

		/*
		For any component you create, override this method and make it return true for every type
		of component that it is.
		*/
		virtual bool IsType(const EComponentTypes& aType) const { return aType == CE_ComponentType_Invalid; }
	};
}

#endif