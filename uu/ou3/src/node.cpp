#include "node.h"

Node::Node()
{
	
}

Node::Node(const Node &n)
{
	Curr = n.Curr->clone();
	if(n.NextNode != NULL)
		NextNode = new Node(*n.NextNode);
	else
		NextNode = NULL;
}

Node::Node(Shape &s, Node *n) : Curr(&s), NextNode(n)
{
	
}

Node::~Node()
{	
	delete Curr;	
	delete NextNode;	
}