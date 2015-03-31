#include "node.h"

Node::Node()
{
	std::cout << "Node()\n";
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
	std::cout << "Node(Shape &, Node *)\n";
	//Curr = s.clone();
	//NextNode = n;
}

Node::~Node()
{
	std::cout << "~Node()\n";
	delete Curr;	
	delete NextNode;	
}