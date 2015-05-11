#ifndef POLYGON_H
#define POLYGON_H
#define POLYGON "POLYGON"
#include "shape.h"
#include "vertex.h"
#include <vector>

class Polygon : public Shape
{
public:
	Polygon(double x, double y, Vertex *vArr, int num);
    Polygon(double x, double y, vector<Vertex> *vect);
	Polygon(const Polygon &); //kopieringskonstruktor
	~Polygon();
	double area(); //override
    void print(ostream& os); //override
	Polygon *clone() const; //override
	
private:
	Vertex *_vArr;
	int _count;
};

#endif
