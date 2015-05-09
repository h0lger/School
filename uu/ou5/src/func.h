#ifndef FUNC_H
#define FUNC_H
class CloseTo
{
public:
    CloseTo (Vertex v) : _v(v) {}
    bool operator() (ShapePtr ptr) const
    {
        return ptr.CloseTo(&_v);
    }
private:
    Vertex _v;
};

#endif // FUNC_H

