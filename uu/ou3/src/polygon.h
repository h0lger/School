#ifndef POLYGON_H
#include "shape.h"
#include "vertex.h"

class Polygon : public Shape
{
public:
	Polygon(double x, double y, Vertex *vArr, int num);
	Polygon(const Polygon &); //kopieringskonstruktor
	~Polygon();
	double area(); //override
	void print(); //override
	Polygon *clone() const; //override
private:
	Vertex *_vArr;
	int _count;
};

#endif