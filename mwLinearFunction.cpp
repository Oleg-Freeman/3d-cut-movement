#include "mwLinearFunction.h"

using namespace std;

mwLinearFunction::mwLinearFunction(const double t1, const double t2)
	:mwDiscreteFunction(t1, t2){}

mwLinearFunction::point3d mwLinearFunction::Evaluate(const double t) const
{
	(void)mwDiscreteFunction::Evaluate(t);

	point3d retValue;
	//
	retValue.x(500. + t);
	retValue.y(250.);
	retValue.z(100.);
	
	return retValue;
}
