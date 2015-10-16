/*
UpdateHandler

Interface to be implemented by anything that wants to receive update events.

Creator:	Charlotte C. Brown
File Date:	October 10th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __UPDATEHANDLER_H
#define __UPDATEHANDLER_H

#include <memory>

namespace CloverEngine
{
	/*
	Any class that wishes to receive frame-by-frame update events needs to
	implement the methods within this interface. Update handlers automatically register themselves with
	the engine - user responsible for memory management, engine will not delete object.
	*/
	class CUpdateHandler
	{
	public:
		CUpdateHandler();
		virtual ~CUpdateHandler();

		// Every engine tick, receives a message with the elapsed time (in seconds) between frames.
		virtual void Update(double aDelta) = 0;
	};
}

#endif