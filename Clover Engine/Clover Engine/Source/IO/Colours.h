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
		CE_Colour_KK = 0,
		CE_Colour_WK,
		CE_Colour_RK,
		CE_Colour_GK,
		CE_Colour_YK,
		CE_Colour_BK,
		CE_Colour_MK,
		CE_Colour_CK,

		CE_Colour_KW,
		CE_Colour_WW,
		CE_Colour_RW,
		CE_Colour_GW,
		CE_Colour_YW,
		CE_Colour_BW,
		CE_Colour_MW,
		CE_Colour_CW,

		CE_Colour_KR,
		CE_Colour_WR,
		CE_Colour_RR,
		CE_Colour_GR,
		CE_Colour_YR,
		CE_Colour_BR,
		CE_Colour_MR,
		CE_Colour_CR,

		CE_Colour_KG,
		CE_Colour_WG,
		CE_Colour_RG,
		CE_Colour_GG,
		CE_Colour_YG,
		CE_Colour_BG,
		CE_Colour_MG,
		CE_Colour_CG,

		CE_Colour_KY,
		CE_Colour_WY,
		CE_Colour_RY,
		CE_Colour_GY,
		CE_Colour_YY,
		CE_Colour_BY,
		CE_Colour_MY,
		CE_Colour_CY,

		CE_Colour_KB,
		CE_Colour_WB,
		CE_Colour_RB,
		CE_Colour_GB,
		CE_Colour_YB,
		CE_Colour_BB,
		CE_Colour_MB,
		CE_Colour_CB,

		CE_Colour_KM,
		CE_Colour_WM,
		CE_Colour_RM,
		CE_Colour_GM,
		CE_Colour_YM,
		CE_Colour_BM,
		CE_Colour_MM,
		CE_Colour_CM,

		CE_Colour_KC,
		CE_Colour_WC,
		CE_Colour_RC,
		CE_Colour_GC,
		CE_Colour_YC,
		CE_Colour_BC,
		CE_Colour_MC,
		CE_Colour_CC,

		CE_Colour_Total
	};
}

#endif