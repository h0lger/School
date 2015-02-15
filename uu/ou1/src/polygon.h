#ifndef POLYGON_H
#include "vertex.h"
//#include <initializer_list>
enum MinMax { Min, Max };
enum Coordinate { X, Y };

class Polygon
{
public:
	Polygon();
	/*Polygon(std::initializer_list<Vertex>);*/
	Polygon(Vertex[], int);
	~Polygon();

	//metoder
	void add(Vertex);
	double area();
	int numVertices();
	int miny();
	int maxy();
	int minx();
	int maxx();	

private:
	Vertex *_vArr;
	int _count;
	int getMinMax(Coordinate, MinMax);
	
};

#endif