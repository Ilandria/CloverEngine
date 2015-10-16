/*
KeyHandler

Interface to be implemented by anything that wants to receive key events.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __KEYHANDLER_H
#define __KEYHANDLER_H

namespace CloverEngine
{
	// Forward declarations
	struct SKeyInfo;

	/*
	Any class that wishes to receive any events from the keyboard needs to extend
	this class and implement its methods. Key handlers automatically register themselves with
	the engine - user responsible for memory management, engine will not delete object.
	*/
	class CKeyHandler
	{
	public:
		CKeyHandler();
		virtual ~CKeyHandler();
		virtual void KeyboardEvent(const SKeyInfo& aEvent) = 0;
	};
}

#endif