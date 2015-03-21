#ifndef POLYGON_H
#include "shape.h"
#include "vertex.h"

class Polygon : public Shape
{
public:
	Polygon(double x, double y, Vertex *vArr, int num);
	~Polygon();
	double area(); //override
private:
	Vertex *_vArr;
	int _count;
};

#endif