#include "mwLinearFunction.h"

#include <iostream>

using namespace std;

mwLinearFunction::mwLinearFunction(const double t1, const double t2, const char d)
	:mwDiscreteFunction(t1, t2), dirrection(d){}

mwLinearFunction::point3d mwLinearFunction::Evaluate(const double t) const
{
	(void)mwDiscreteFunction::Evaluate(t);

	point3d retValue;
	switch (dirrection)
	{
	case 'X' :
		retValue.x(10. + t);
		retValue.y(10.);
		retValue.z(7.);
	case 'Y':
		retValue.x(10.);
		retValue.y(10. + t);
		retValue.z(7.);
	case 'Z' :
		retValue.x(10.);
		retValue.y(10.);
		retValue.z(7. + t);
	default :
		throw misc::mwException(0, "Invalid sphere movement dirrection");
	}

	return retValue;
}
