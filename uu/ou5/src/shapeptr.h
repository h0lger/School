#ifndef SHAPEPTR
#define SHAPEPTR
#include "shape.h"
#include <iostream>

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

