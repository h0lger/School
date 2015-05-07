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

       s._ptr = new Point(x, y, size);
    }
    else if(type == RECTANGLE)
    {        
        double width, height;
        is >> width;
        is >> height;
        s._ptr = new Rectangle(x, y, width, height);
    }
    else if(type == CIRCLE)
    {        
        double r;
        is >> r;
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
        vector<Vertex*> vectVertex;
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

            vectVertex.push_back(new Vertex(vX, vY));

        }
        //skapa polygon
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
