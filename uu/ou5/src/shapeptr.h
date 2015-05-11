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
    ShapePtr(const ShapePtr &sPtr); //kopieringskonstruktor
    ~ShapePtr();
    friend std::istream& operator>>(std::istream &is, ShapePtr &s);
    friend std::ostream& operator<<(std::ostream &os, const ShapePtr &s);
    bool CloseTo(const Vertex *v);
    ShapePtr *clone() const;
    const ShapePtr& operator=(const ShapePtr& sPtr);
    //bool operator <(const ShapePtr &s);

    static bool SortBySize(const ShapePtr &s1, const ShapePtr &s2);
    static bool SortByXPos(const ShapePtr &s1, const ShapePtr &s2);
    static bool SortByYPos(const ShapePtr &s1, const ShapePtr &s2);
    static int NumShapes;
private:
    Shape * _ptr;
};

#endif

