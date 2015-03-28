#ifndef NODE_H
#define NODE_H
#include "shape.h"
class Node
{
public:
	//konstruktorer
	Node();
	Node(const Node &); //kopieringskonstruktor
	Node(Shape *, Node *);
	~Node();
	
	Shape *Curr; //aktuell
	Node *NextNode;	//nästa
};


#endif