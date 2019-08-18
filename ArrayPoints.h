#pragma once
#ifndef ArrayPoints_H
#define ArrayPoints_H

//defined class for storing, comparing, deleting and printing 3dpoints

#include "CreateSkin.hpp"
//Alias for cadcam::mwTPoint3d<double> simpler access
typedef cadcam::mwTPoint3d<double> point3d;
#include <vector> //container to store 3dpoint objects
#include <string> //std::string
#include <fstream> //std::ostream

using namespace std;
class ArrayPoints
{
public:
	//constructor
	ArrayPoints(const point3d, const unsigned long, const unsigned long, 
		const unsigned long, const double, const string);

	void printArray(); //print point coordinates X, Y, Z to specified file

	//compare length of mathematical vector with sphere radius and
	//delete not needed points
	void delArrayElem(vector<point3d>::iterator &, double &, const double);

	//calculate mathematical vector with begin at sphere center point
	// and with end at iterating point from point cloud
	void VCalculate(mwDiscreteFunction &, const double, const double);

private:
	vector<point3d> Arr; //container to store 3dpoints
	vector<point3d>::iterator itr; //iterate through container of 3dpoints
	ofstream fout; //print coordinates ti file
};

#endif // ArrayPoints

