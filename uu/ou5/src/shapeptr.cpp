#include "shapeptr.h"

ShapePtr::ShapePtr()
{
    _ptr = 0;
}
ShapePtr::ShapePtr(Shape *shape): _ptr(shape)
{

}

std::istream& operator >>(std::istream& is, ShapePtr& s)
{
    string type;
    double x, y;
    is >> type;

    //gemensamt för alla typer
    is >> x;
    is >> y;

    if(type == POINT)
    {
        double size;
        is >> size;
    }
    else if(type == RECTANGLE)
    {
        double width, height;
        is >> width;
        is >> height;
    }
    else if(type == CIRCLE)
    {
        double r;
        is >> r;
    }
    else if(type == POLYGON)
    {

    }
    else
    {
        cerr << "Felaktig typ";
    }

    return is;
}

std::ostream& operator <<(std::ostream& os, const ShapePtr& s)
{    
    s._ptr->print(os);
    return os;
}
