/*
WindowHandler

Interface to be implemented by all windows in order to be rendered appropriately

Creator:	Charlotte C. Brown
File Date:	October 11th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __WINDOWHANDLER_H
#define __WINDOWHANDLER_H

namespace CloverEngine
{
	/*
	Any window that wishes to be able to render itself on the screen needs to extend this
	class and implement its methods. Window handlers automatically register themselves with
	the engine - user responsible for memory management, engine will not delete object.
	*/
	class CWindowHandler
	{
	public:
		CWindowHandler();
		virtual ~CWindowHandler();

		// This is where any logic related to drawing the window takes place, such as shaders.
		virtual void Render() = 0;

		// Empties the window's internal buffer.
		virtual void Erase() = 0;

		// Empties and completely clears the window's current state. Causes flickering when called.
		virtual void Clear() = 0;
	};
}

#endif