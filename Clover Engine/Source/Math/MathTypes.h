/*
MathTypes

Various structs that define commonly used math data types.

Creator:	Charlotte C. Brown
File Date:	October 16th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __MATHTYPES_H
#define __MATHTYPES_H

namespace CloverEngine
{
	template<typename T>
	struct SVector2
	{
		T m_X;
		T m_Y;
	};
}

#endif