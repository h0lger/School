#ifndef VERTEX_H
#define VERTEX_H
#define VERTEX VERTEX
#include <iostream>


class Vertex
{
public:
	Vertex();
	Vertex(const Vertex &); //kopieringskonstruktor
	Vertex(int, int);
	~Vertex(); 

	//metoder
	const Vertex& operator=(const Vertex& v);
	int X() const;
	int Y() const;
	
	friend std::ostream& operator<<(std::ostream&, const Vertex&);

private:
	int _x;
	int _y;
	
};

#endif
