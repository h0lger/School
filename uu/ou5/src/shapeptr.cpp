#include "shapeptr.h"

int ShapePtr::NumShapes = 0;

bool ShapePtr::SortBySize(const ShapePtr &s1, const ShapePtr &s2)
{
    return s1._ptr->area() < s2._ptr->area();
}

bool ShapePtr::SortByXPos(const ShapePtr &s1, const ShapePtr &s2)
{
    return s1._ptr->getX() < s2._ptr->getX();
}

bool ShapePtr::SortByYPos(const ShapePtr &s1, const ShapePtr &s2)
{
    return s1._ptr->getY() < s2._ptr->getY();
}

ShapePtr::ShapePtr()
{
    ShapePtr::NumShapes++;
    _ptr = 0;
}
ShapePtr::ShapePtr(Shape *shape): _ptr(shape)
{
    ShapePtr::NumShapes++;
}

ShapePtr::ShapePtr(const ShapePtr &sPtr)
{
    ShapePtr::NumShapes++;
    if (sPtr._ptr != 0)
        _ptr = sPtr._ptr->clone();
    else
        _ptr = 0;
}

ShapePtr::~ShapePtr()
{
    NumShapes--;
    delete _ptr;
}

const ShapePtr& ShapePtr::operator =(const ShapePtr &sPtr)
{
    delete _ptr;
    if(this != &sPtr)
    {
        if (sPtr._ptr != 0)
            _ptr = sPtr._ptr->clone();
        else
            _ptr = 0;
    }

    return *this;
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
        delete s._ptr;
        s._ptr = new Point(x, y, size);
    }
    else if(type == RECTANGLE)
    {        
        double width, height;
        is >> width;
        is >> height;
        delete s._ptr;
        s._ptr = new Rectangle(x, y, width, height);
    }
    else if(type == CIRCLE)
    {        
        double r;
        is >> r;
        delete s._ptr;
        s._ptr = new Circle(x, y, r);
    }
    else if(type == POLYGON)
    {
        cout << "Skapar polygon\n";
        string vertexPos;
        int vX, vY; //vertex
        bool end = false;
        is >> vertexPos;
        vertexPos.replace(0, 1, "");
        vector<Vertex> vectVertex;
        //skapa upp alla vertex
        while(!end)
        {
            vX = std::stoi(vertexPos);
            is >> vertexPos;
            //vertex slut
            if(vertexPos.find('>') != string::npos)
            {
                end = true;
                vY = std::stoi(vertexPos.replace(vertexPos.end() - 1, vertexPos.end(), ""));
            }
            else
            {
                vY = std::stoi(vertexPos);
                is >> vertexPos; //gå till nästa
            }

            vectVertex.push_back(Vertex(vX, vY));
        }

        //skapa polygon
        delete s._ptr;
        s._ptr = new Polygon(x, y, &vectVertex);

    }
    else
    {
        //eventuella tomma rader ignorerar vi
        if(type != "")
            cerr << "Felaktig typ";
    }

    return is;
}

std::ostream& operator <<(std::ostream& os, const ShapePtr& s)
{    
    s._ptr->print(os);
    return os;
}

bool ShapePtr::CloseTo(const Vertex *v)
{
    return
            (fabs(_ptr->getX() - v->X()) <= 1) ||
            (fabs(_ptr->getY() - v->Y()) <= 1);
}

ShapePtr *ShapePtr::clone() const
{
    ShapePtr *tmp = new ShapePtr(*this);
    return tmp;
}
