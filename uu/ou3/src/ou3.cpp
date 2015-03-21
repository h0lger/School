#include <iostream>
#include "polygon.h"
#include "point.h"
#include "circle.h"
#include "rectangle.h"
using namespace std;

int main()
{
	Point p(10, 20, 50);
	cout << p.area() << "\n";
	
	Circle c(10, 10, 10);
	cout << c.area() << "\n";
	
	Rectangle r(1, 1, 10, 10);
	cout << r.area() << "\n";
	
	Vertex vArr[] = { Vertex(0, 0), Vertex(10, 0), 
										Vertex(5, 2), Vertex(5, 5)};
										
	Polygon pl(1, 1, vArr, 4);
	cout << pl.area() << "\n";
	return 0;
}