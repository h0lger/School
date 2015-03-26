#ifndef NODE_H
#define NODE_H
#include "shape.h"
class Node
{
public:
	Shape *CurrNode; //aktuell
	Node *NextNode;	//nästa
};


#endif