#pragma once
#ifndef MWLINEARFUNCTION_H
#define MWLINEARFUNCTION_H

#include "mwDiscreteFunction.hpp"

class mwLinearFunction :
	public mwDiscreteFunction
{
public:
	mwLinearFunction(const double, const double, const char);
	point3d Evaluate(const double) const;
private:
	const char dirrection;
};

#endif


