#ifndef SHAPE_LIST_H
#define SHAPE_LIST_H
#include "shape.h"
#include "vertex.h"
class ShapeList
{
public:
	ShapeList();
	ShapeList( const ShapeList &shapes); // kopieringskonstruktor
	~ShapeList();
	
	void add( const Shape& s );
	void remove( const Vertex &v); // ta bort alla figurer "nära" v
	double area(); // returnerar den totala ytan av alla figurer
	void print(); // skriv ut listan
};
#endif