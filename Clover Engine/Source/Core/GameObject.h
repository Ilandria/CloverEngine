/*
GameObject

The base object for everything within the game world.

Creator:	Charlotte C. Brown
File Date:	October 16th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

#include <vector>

namespace CloverEngine
{
	// Forward declarations.
	class CComponent;
	class CTransform;
	class CDrawBuffer;

	/*
	Everything that can be added to the game world is a GameObject. GameObjects contain a list of
	all of the Components that make them up as well as manage adding, removing, and deleting those
	components. All GameObjects always have exactly 1 transform and 1 draw buffer.
	*/
	class CGameObject
	{
	private:
		// All of the components that currently make up this game object, including those listed below.
		std::vector<CComponent*> m_Components;

		// This GameObject's transform component, for quick reference.
		CTransform* m_Transform;

		// This GameObject's draw buffer component, for quick reference.
		CDrawBuffer* m_DrawBuffer;

	public:
		// TODO: Finish implementing GameObject.
		CGameObject();
		virtual ~CGameObject();
	};
}

#endif