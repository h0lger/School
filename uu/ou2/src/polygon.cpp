#include "polygon.h"

//konstruktorer
Polygon::Polygon()
{
	_count = 0;
};

Polygon::Polygon(const Polygon& pol)
{
	std::cout << "Kopieringskonstruktor";
}

Polygon::Polygon(Vertex vA[], int antal)
{	
	_vArr = new Vertex[antal - 1];

	for (int i = 0; i < antal; i++)
	{
		_vArr[i] = vA[i];
	}

	_count = antal;
}

Polygon::~Polygon()
{
	//delete [] _vArr;
};

//metoder
Polygon& Polygon::operator =(const Polygon& pol)
{	
	_count = 0;
	_vArr = new Vertex[pol._count];
	//kopiera över vertex vektorn
	for(int i = 0;i<pol._count;i++)
	{
		_vArr[i] = pol._vArr[i];
		_count++;
	}
	
	//Kontroll
	if(_count != pol._count)
		std::cerr << "Fel vid tilldelningoperator\n";
	
	return *this;
}

void Polygon::add(Vertex v)
{		
	Vertex* tmp = new Vertex[_count + 1]();

	//kopiera till tmp
	for (int i = 0; i < _count; i++)
	{		
		tmp[i] = _vArr[i];
	}
	
	//lägg till ny
	tmp[_count] = v;
		
	
	//rensa gammal
	if(_count > 0)
		delete[] _vArr;
	
	_count++;
	
	_vArr = tmp;		
}

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

int Polygon::numVertices()
{
	return _count;
}

int Polygon::miny() const
{
	return getMinMax(Y, Min);
}

int Polygon::maxy() const
{
	return getMinMax(Y, Max);	
}

int Polygon::minx() const
{
	return getMinMax(X, Min);	
}

int Polygon::maxx() const
{
	return getMinMax(X, Max);		
}

int Polygon::getMinMax(Coordinate crd, MinMax m) const
{
	int minmax = 0;
	int tmp = 0;
	//startvärde
	if(crd == X)
		minmax = _vArr[0].X();
	else
		minmax = _vArr[0].Y();

	for (int i = 1; i < _count; i++)
	{
		if(crd == X)		
			tmp = _vArr[i].X();		
		else //Y
			tmp = _vArr[i].Y();		

		if(m == Max && tmp > minmax)
			minmax = tmp;		
		else if(m == Min && tmp < minmax)
			minmax = tmp;
	}

	return minmax;
}

bool Polygon::operator <(const Polygon& pol) const
{
	return (maxy() < pol.maxy() && maxx() < pol.maxx());	
}

std::ostream& operator <<(std::ostream& os, const Polygon& pol)
{
	os << "{";
	for(int i = 0; i < pol._count; i++)
	{
		os << pol._vArr[i] << " ";
	}
	
	os << "}";
	
	return os;
}
