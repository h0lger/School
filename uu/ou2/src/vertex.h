#ifndef VERTEX_H
#include <iostream>

class Vertex
{
public:
	Vertex();
	Vertex(const Vertex &);
	Vertex(int, int);
	~Vertex();

	//metoder
	int X();
	int Y();
	
	friend std::ostream& operator<<(std::ostream&, const Vertex&);

private:
	int _x;
	int _y;
	
};

#endif