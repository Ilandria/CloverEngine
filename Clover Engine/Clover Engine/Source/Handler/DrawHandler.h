/*
DrawHandler

Interface to be implemented by anything that wants to draw itself on the screen.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __DRAWHANDLER_H
#define __DRAWHANDLER_H

namespace CloverEngine
{
	/*
	Any class that wishes to be able to draw itself on the screen needs to extend this
	class and implement its methods. Draw handlers automatically register themselves with
	the engine - user responsible for memory management, engine will not delete object.
	*/
	class CDrawHandler
	{
	public:
		CDrawHandler();
		virtual ~CDrawHandler();
		virtual void Draw() = 0;
	};
}

#endif