/*
Colours

Easy reference for all of the engine's default colours.

Creator:	Charlotte C. Brown
File Date:	October 4th, 2015
Contact:	charlotte.clover.brown@gmail.com
Website:	http://charlottebrown.ca/
*/

#ifndef __COLOURS_H
#define __COLOURS_H

namespace CloverEngine
{
	/*
	Contains all of the default colour pairs that are initialized by the game engine.
	The first character is the foreground colour, the second is the background colour.
	Colours are as follows: Black (K), White (W), Red (R), Green (G), Blue (B),
	Yellow (Y), Magenta (M), Cyan (C), Console Default (D).
	*/
	enum EColours
	{
		CE_COLOUR_KK = 0,
		CE_COLOUR_WK,
		CE_COLOUR_RK,
		CE_COLOUR_GK,
		CE_COLOUR_YK,
		CE_COLOUR_BK,
		CE_COLOUR_MK,
		CE_COLOUR_CK,

		CE_COLOUR_KW,
		CE_COLOUR_WW,
		CE_COLOUR_RW,
		CE_COLOUR_GW,
		CE_COLOUR_YW,
		CE_COLOUR_BW,
		CE_COLOUR_MW,
		CE_COLOUR_CW,

		CE_COLOUR_KR,
		CE_COLOUR_WR,
		CE_COLOUR_RR,
		CE_COLOUR_GR,
		CE_COLOUR_YR,
		CE_COLOUR_BR,
		CE_COLOUR_MR,
		CE_COLOUR_CR,

		CE_COLOUR_KG,
		CE_COLOUR_WG,
		CE_COLOUR_RG,
		CE_COLOUR_GG,
		CE_COLOUR_YG,
		CE_COLOUR_BG,
		CE_COLOUR_MG,
		CE_COLOUR_CG,

		CE_COLOUR_KY,
		CE_COLOUR_WY,
		CE_COLOUR_RY,
		CE_COLOUR_GY,
		CE_COLOUR_YY,
		CE_COLOUR_BY,
		CE_COLOUR_MY,
		CE_COLOUR_CY,

		CE_COLOUR_KB,
		CE_COLOUR_WB,
		CE_COLOUR_RB,
		CE_COLOUR_GB,
		CE_COLOUR_YB,
		CE_COLOUR_BB,
		CE_COLOUR_MB,
		CE_COLOUR_CB,

		CE_COLOUR_KM,
		CE_COLOUR_WM,
		CE_COLOUR_RM,
		CE_COLOUR_GM,
		CE_COLOUR_YM,
		CE_COLOUR_BM,
		CE_COLOUR_MM,
		CE_COLOUR_CM,

		CE_COLOUR_KC,
		CE_COLOUR_WC,
		CE_COLOUR_RC,
		CE_COLOUR_GC,
		CE_COLOUR_YC,
		CE_COLOUR_BC,
		CE_COLOUR_MC,
		CE_COLOUR_CC,

		CE_NUM_COLOURS
	};
}

#endif