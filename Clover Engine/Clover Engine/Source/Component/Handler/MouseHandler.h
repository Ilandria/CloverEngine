/*
MouseHandler

Interface to be implemented by anything that wants to receive mouse events.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __MOUSEHANDLER_H
#define __MOUSEHANDLER_H

namespace CloverEngine
{
	// Forward declarations
	struct SMouseInfo;

	/*
	Any class that wishes to receive any events from the mouse needs to extend
	this class and implement its methods. Mouse handlers automatically register themselves with
	the engine - user responsible for memory management, engine will not delete object.
	*/
	class CMouseHandler
	{
	public:
		CMouseHandler();
		virtual ~CMouseHandler();
		virtual void MouseEvent(const SMouseInfo& aEvent) = 0;
	};
}

#endif