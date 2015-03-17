#ifndef POLYGON_H
#include "shape.h"
#include "vertex.h"

class Polygon : public Shape
{
	Polygon(double x, double y, Vertex *vArr, int num);
	~Polygon();
};

#endif