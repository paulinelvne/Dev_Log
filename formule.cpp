#include "formule.h"
#include <iostream>

bool transforme(int xA, int ope, int xB=36)
{
	if(xB==36)
	{
		return(!xA);
	}
	else if(ope == 3)
	{
		return(xA && xB);
	}
	else if(ope == 2)
	{
		return(xA || xB);
	}
}