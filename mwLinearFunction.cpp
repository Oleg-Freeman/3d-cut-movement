#include "mwLinearFunction.h"

using namespace std;

mwLinearFunction::mwLinearFunction(const double t1, const double t2, const char d)
	:mwDiscreteFunction(t1, t2), dirrection(d){}

mwLinearFunction::point3d mwLinearFunction::Evaluate(const double t) const
{
	(void)mwDiscreteFunction::Evaluate(t);

	point3d retValue;
	//
	retValue.x(10. + t);
	retValue.y(10.);
	retValue.z(7.);
	
	return retValue;
}
