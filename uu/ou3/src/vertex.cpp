#include "vertex.h"

//konstruktorer
Vertex::Vertex() { };
Vertex::Vertex(const Vertex &v)
{
	_x = v._x;
	_y = v._y;	
}
Vertex::~Vertex() {};
Vertex::Vertex(int x, int y)
{
	//sätt koordinater
	_x = x;
	_y = y;
}

//metoder
int Vertex::X() { return _x; }
int Vertex::Y() { return _y; }

const Vertex& Vertex::operator =(const Vertex& v)
{	
	if(this != &v)
	{
		_x = v._x;
		_y = v._y;
	}
	
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vertex& ver)
{
	os << "(" << ver._x << "," << ver._y << ")";
	
	return os;
}


