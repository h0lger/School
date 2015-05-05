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
    return is;
}

std::ostream& operator <<(std::ostream& os, const ShapePtr& s)
{
    return os;
}
