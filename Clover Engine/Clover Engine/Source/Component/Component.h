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
		CE_ComponentType_DrawBuffer,
		CE_ComponentType_Transform,
		CE_ComponentType_LastIndex
	};

	// Forward declarations.
	class CGameObject;

	/*
	Components can be almost anything imaginable. If you wish to add functionality to a GameObject,
	you must either use a pre-made component or create your own component and add an instance of it
	to said GameObject. The base component has almost no functionality beyond simply tracking what
	kind of component it is. This of these as the core lego blocks of any CloverEngine game.
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
		of component that it is. Takes an int in order to allow users to define their own types.
		The engine uses all indexes between 0 and EComponentTypes::CE_ComponentType_LastIndex
		(inclusive) for its pre-defined component types. Use the EComponentTypes enumerator to
		have easy reference to the engine's built-in types.
		*/
		virtual bool IsType(const int& aType) const { return aType == CE_ComponentType_Invalid; }
	};
}

#endif