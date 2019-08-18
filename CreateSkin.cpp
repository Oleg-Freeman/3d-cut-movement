#include "CreateSkin.hpp"
#include "ArrayPoints.h"//defined class for storing, comparing
//deleting and printing 3dpoints

using namespace std;

void CreateSkin( const cadcam::mwTPoint3d<double> refPoint, 
				const unsigned long nx, const unsigned long ny, 
				const unsigned long nz, const double sphereRad, 
				mwDiscreteFunction &func, const double deltaT,
				const double delta, const string &skinFileName )
{

	//Your source code here...
	//Creating new ArrayPoints object
	ArrayPoints points(refPoint, nx, ny, nz, delta, skinFileName);

	//calculate length of mathematical vector with begin at sphere center point
	// and with end at iterating point from point cloud,
	//compare it with sphere radius and
	//delete not needed points
	points.VCalculate(func, sphereRad, deltaT);

	//print point coordinates X, Y, Z to specified file
	points.printArray();
	


}

