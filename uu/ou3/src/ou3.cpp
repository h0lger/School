#include <iostream>
#include "polygon.h"
#include "point.h"
#include "circle.h"
#include "rectangle.h"
#include "shapelist.h"
using namespace std;

int main()
{
	Point p(10, 20, 50);
	cout << p.area() << "\n";
	p.print();
	
	Circle c(10, 10, 10);
	cout << c.area() << "\n";
	c.print();
	
	Rectangle r(1, 1, 10, 10);
	cout << r.area() << "\n";
	r.print();
	
	Vertex vArr[] = { Vertex(0, 0), Vertex(10, 0), 
										Vertex(5, 2), Vertex(5, 5)};
										
	Polygon pl(1, 1, vArr, 4);
	cout << pl.area() << "\n";
	pl.print();
	
	//test av klon
	cout << "TEST AV KLON:\n";
	Circle *c2 = c.clone();
	c2->print();
	Polygon *p2 = pl.clone();
	p2->print();
	
	cout << "TEST AV LISTA:\n";
	ShapeList lista = ShapeList();
	Shape *cPtr = &c;
	Shape *pPtr = &p;
	Shape *rPtr = &r;
	Shape *plPtr = &pl;
	lista.add(*cPtr);
	lista.add(*pPtr);
	lista.add(*rPtr);
	lista.add(*plPtr);	
	lista.print();
	cout << "TOT AREA: " << lista.area() << "\n";
	cout << "NU TAR VI BORT\n";
	lista.remove(Vertex(10, 10));
	lista.print();
	
	
	return 0;
}