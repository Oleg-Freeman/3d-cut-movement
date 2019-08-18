#include "ArrayPoints.h"

#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

//constructor, which opens file for printing and fills container with
//3dpoint objects
ArrayPoints::ArrayPoints(const point3d p, const unsigned long x,
	const unsigned long y, const unsigned long z, const double d, const string name)
{
	//open specified file for printing
	fout.open(name, ios::out);
	//filling container with 3dpoint objects
	//we can fill only the last top layer sinse we don`t need other layers
	for (double iy = p.y(); iy < y; iy = iy + d)
	{
		for (double ix = p.x(); ix < x; ix = ix + d)
		{
			//Initializing new point3d with X, Y, Z coordinates
			point3d *p1 = new point3d(ix,iy,z);
			Arr.push_back(*p1);
		}
	}
}

//Function to print point coordinates X, Y, Z to specified file
void ArrayPoints::printArray()
{
	int count{ 0 };
	for (itr = Arr.begin(); itr < Arr.end(); ++itr)
	{
		//printing to file each coordinate in 0.0 format
		fout << fixed << setprecision(1) << itr->x() << " " << itr->y() << " " << itr->z() << endl;
		++count;

	}
	//fout << endl << "Number of points = " << count;
}

//Function to delete iterated point
void ArrayPoints::delArrayElem(vector<point3d>::iterator &i, double &v, const double r1)
{
	//Checking if length of calculated vector is less then sphere radius
	//then delete point
	if (v <= r1) itr = Arr.erase(i);
}

//This function calculates mathematical vector with begin at sphere center point
// and with end at iterating point from point cloud
void ArrayPoints::VCalculate(mwDiscreteFunction &f, const double r, const double dT)
{	
	for (int g = (int)f.GetBeginParameter(); g <= (int)(f.GetEndParameter()*100); g = g + (int)(dT*100))
	{
		//Iterating through container to find not needed points
		for (itr = Arr.begin(); itr < Arr.end(); ++itr)
		{
			//Calculating length of mathimatical vector 
			//with begin at sphere center point and with end at iterating point 
			//from point cloud with coordinates Vx, Vy, Vz
			double Vx = f.Evaluate(((double)g / 100.0)).x() - itr->x();
			double Vy = f.Evaluate(((double)g / 100.0)).y() - itr->y();
			double Vz = f.Evaluate(((double)g / 100.0)).z() - itr->z();
			double VLength = sqrt(pow(Vx, 2) + pow(Vy, 2) + pow(Vz, 2));
			
			//Call function to compare vector length with sphere radius and remove
			//not needed point
			//fout << "Coordinate X is " << f.Evaluate(((double)g / 100.0)).x() << endl;
			//fout << "Coordinate Y is " << f.Evaluate(((double)g / 100.0)).y() << endl;
			//fout << "Coordinate Z is " << f.Evaluate(((double)g / 100.0)).z() << endl;
			delArrayElem(itr, VLength, r);
		}
	}
}