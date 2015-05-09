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
#include <math.h>

class ShapePtr
{
public:
    ShapePtr();
    ShapePtr(Shape *shape);
    friend std::istream& operator>>(std::istream &is, ShapePtr &s);
    friend std::ostream& operator<<(std::ostream &os, const ShapePtr &s);
    bool CloseTo(const Vertex *v);
private:
    Shape * _ptr;
};

#endif

