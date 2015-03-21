#include "polygon.h"

//Konstruktor
Polygon::Polygon(double x, double y, Vertex *v, int num) : Shape(x, y)
{
	_vArr = v;
	_count = num;
}

Polygon::~Polygon()
{	
	delete [] _vArr;
};

double Polygon::area()
{
	double area = 0, sista = 0;	
	
	for (int i = 0; i < _count - 1; i++)
	{		
		area += (_vArr[i].X() * _vArr[i+1].Y() - _vArr[i+1].X() * _vArr[i].Y()) / 2.0;
	}

	sista = (_vArr[_count - 1].X() * _vArr[0].Y() - _vArr[0].X() * _vArr[_count - 1].Y()) / 2;
	
	area += sista;	
	
	if(area < 0)
		area = area * -1;
	
	return area;
}