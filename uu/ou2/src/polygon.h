#ifndef POLYGON_H
#include "vertex.h"
#include <iostream>

enum MinMax { Min, Max };
enum Coordinate { X, Y };

class Polygon
{
public:
	Polygon();
	Polygon(const Polygon& pol); //kopieringskonstruktor	
	Polygon(Vertex[], int);
	~Polygon();	

	//metoder
	void add(Vertex);
	double area();
	int numVertices();
	int miny() const;
	int maxy() const;
	int minx() const;
	int maxx() const;
	bool operator<(const Polygon& pol) const;
	Polygon& operator=(const Polygon& pol); //tilldelningsoperators
	friend std::ostream& operator<<(std::ostream& os, const Polygon& pol);

private:
	Vertex *_vArr;
	int _count;
	int getMinMax(Coordinate, MinMax) const;
	
};

#endif