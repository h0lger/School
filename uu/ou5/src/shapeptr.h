#ifndef SHAPEPTR
#define SHAPEPTR
#include "shape.h"
#include "polygon.h"
#include "circle.h"
#include "point.h"
#include "rectangle.h"
#include <iostream>
#include <string>
#include <vector>

class ShapePtr
{
public:
    ShapePtr();
    ShapePtr(Shape *shape);
    friend std::istream& operator>>(std::istream &is, ShapePtr &s);
    friend std::ostream& operator<<(std::ostream &os, const ShapePtr &s);
private:
    Shape * _ptr;
};

#endif

