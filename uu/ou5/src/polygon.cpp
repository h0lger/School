#include "polygon.h"

//Konstruktor
Polygon::Polygon(double x, double y, Vertex *v, int num) : Shape(x, y)
{
	_vArr = new Vertex[num];
	for(int i = 0;i<num;i++)
	{
		_vArr[i] = Vertex(v[i]);
	}	
	_count = num;
}

Polygon::Polygon(double x, double y, vector<Vertex> *vect) : Shape(x, y)
{
    _vArr = new Vertex[vect->size()];
    int i = 0;
    for(vector<Vertex>::iterator iter = vect->begin();iter != vect->end();iter++)
    {
        Vertex v = *iter;
        _vArr[i] = Vertex(v);
        i++;
    }
    _count = i;
}

Polygon::Polygon(const Polygon &p) : Shape(p._x, p._y)
{
	_vArr = new Vertex[p._count];
	for(int i = 0;i<p._count;i++)
	{
		_vArr[i] = Vertex(p._vArr[i]);
	}
	
	_count = p._count;
}


Polygon::~Polygon()
{		
	delete [] _vArr;
};

double Polygon::area()
{
	double area = 0, sista = 0;	
	
	for (int i = 0; i < _count - 1; i++)
	{		
		area += (_vArr[i].X() * _vArr[i+1].Y() - _vArr[i+1].X() * _vArr[i].Y()) / 2.0;
	}

	sista = (_vArr[_count - 1].X() * _vArr[0].Y() - _vArr[0].X() * _vArr[_count - 1].Y()) / 2;
	
	area += sista;	
	
	if(area < 0)
		area = area * -1;
	
	return area;
}

void Polygon::print(ostream& os)
{    
    os << POLYGON " ";
    Shape::print(os);
    os << "<";
	for(int i = 0;i<_count;i++)
	{
        os << _vArr[i];
        if(i < (_count - 1))
            os << " ";
	}    
    os << ">";
	
}

Polygon *Polygon::clone() const
{
	return new Polygon(*this);	
}
