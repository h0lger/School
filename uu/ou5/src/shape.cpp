#include "shape.h"
#include "shapeptr.h"

Shape::Shape(double x, double y)
{
    //ShapePtr::NumShapes++;
	_x = x;
	_y = y;
}

Shape::Shape(const Shape &s)
{
    //ShapePtr::NumShapes++;
	_x = s._x;
	_y = s._y;
}

Shape::~Shape()
{
    //ShapePtr::NumShapes--;
	_x = 0;
	_y = 0;
}

//Positionen
void Shape::print(ostream& os)
{
    os << _x << " " << _y << " ";
}

double Shape::area()
{
	std::cout << "Ska inte användas\n";
	return 0;
}


Shape* Shape::clone() const
{
	return new Shape(*this);	
}

double Shape::getX()
{
	return _x;
}

double Shape::getY()
{
	return _y;
}
