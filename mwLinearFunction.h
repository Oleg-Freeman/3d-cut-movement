#pragma once
#ifndef MWLINEARFUNCTION_H
#define MWLINEARFUNCTION_H

#include "mwDiscreteFunction.hpp"

class mwLinearFunction :
	public mwDiscreteFunction
{
public:
	mwLinearFunction(const double, const double);
	point3d Evaluate(const double) const;
};

#endif


