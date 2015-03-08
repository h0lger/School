#ifndef VERTEX_H

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

private:
	int _x;
	int _y;
	
};

#endif