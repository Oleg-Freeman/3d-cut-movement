//Additional class for linear sphere movement
#include "mwLinearFunction.h"

using namespace std;
//Constructor with t1 and t2 arguments
mwLinearFunction::mwLinearFunction(const double t1, const double t2)
	:mwDiscreteFunction(t1, t2){}
//Overrided Evaluate function
mwLinearFunction::point3d mwLinearFunction::Evaluate(const double t) const
{
	(void)mwDiscreteFunction::Evaluate(t);

	point3d retValue;
	//Moves sphere center to X dirrection, t = t + dt
	retValue.x(500. + t);
	retValue.y(250.);
	retValue.z(100.);
	
	return retValue;
}
