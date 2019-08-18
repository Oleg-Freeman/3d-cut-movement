//Additional class for linear sphere movement
#pragma once
#ifndef MWLINEARFUNCTION_H
#define MWLINEARFUNCTION_H

#include "mwDiscreteFunction.hpp"

class mwLinearFunction :
	public mwDiscreteFunction
{
public:
	mwLinearFunction(const double, const double);//Constructor with two arguments
	point3d Evaluate(const double) const;//Overrided Evaluate virual function
};

#endif


