#include "node.h"

Node::Node()
{
	std::cout << "Node()";
}

Node::Node(const Node &n)
{
	Curr = n.Curr;
	NextNode = new Node(*n.NextNode);
}

Node::Node(Shape *s, Node *n)
{
	Curr = s;
	NextNode = n;
}

Node::~Node()
{
	std::cout << "~Node()";
	delete Curr;
	delete NextNode;	
}