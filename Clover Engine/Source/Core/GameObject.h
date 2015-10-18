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

#include <string>
#include <vector>

namespace CloverEngine
{
	// Forward declarations.
	class CTransform;

	/*
	Everything that can be added to the game world is a GameObject. GameObjects contain a list of
	all of the Components that make them up as well as manage adding, removing, and deleting those
	components. All GameObjects always have exactly 1 transform and 1 draw buffer.
	*/
	class CGameObject final
	{
	private:
		// All of the components that currently make up this game object, including those listed below.
		std::vector<CComponent*> m_Components;

		// This GameObject's transform component, for quick reference.
		CTransform* m_Transform;

	public:
		// TODO: Finish implementing GameObject.
		CGameObject();
		virtual ~CGameObject();

		// Gets this GameObject's transform component.
		CTransform* GetTransform();

		// Add a component to the GameObject. You can not add another transform.
		CComponent* AddComponent(CComponent* aComponent);

		/* Gets the first component in the GameObject that are of the requested type. This will
		return a null pointer if no components match. Use EComponentTypes for built-in engine
		types, or your own reference if you have defined custom types. */
		CComponent* GetComponent(const int& aType);

		/* Gets the first component in the GameObject whos name matches the given name. This will
		return a null pointer if no components match. */
		CComponent* GetComponent(const std::string& aName);

		// Gets all of the components in this GameObject.
		std::vector<CComponent*> GetComponents();

		/* Gets all of the components in the GameObject that are of the requested type. This will
		return an empty vector if no components match. Use EComponentTypes for built-in engine
		types, or your own reference if you have defined custom types. */
		std::vector<CComponent*> GetComponents(const int& aType);

		/* Gets all of the components in the GameObject whos names match the given name. This will
		return an empty vector if no components match. */
		std::vector<CComponent*> GetComponents(const std::string& aName);
	};
}

#endif