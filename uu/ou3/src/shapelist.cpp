#include "shapelist.h"

ShapeList::ShapeList()
{	
	_node = NULL;
}

ShapeList::ShapeList(const ShapeList &s)
{
	_node = new Node(*_node); //skapar en kopia	
}

ShapeList::~ShapeList()
{
	std::cout << "TODO destruktor\n";
}

void ShapeList::add(const Shape &s)
{
	Shape *tmp = s.clone(); //skapa en kopia
	
	_node = new Node(tmp, _node);
	
}

void ShapeList::print()
{
	Node *tmp = _node;
	while(tmp != NULL)
	{
		tmp->Curr->print();
		tmp = tmp->NextNode;
	}
	std::cout << "\n";
	
}

double ShapeList::area()
{
	double area = 0;
	Node *tmp = _node;
	while(tmp != NULL)
	{
		area += tmp->Curr->area();
		tmp = tmp->NextNode;
	}
	
	return area;
}

void ShapeList::remove(const Vertex &v)
{
	Node *tmp = _node;
	while(tmp != NULL)
	{
		if((tmp->NextNode != NULL) &&
		(std::abs(tmp->NextNode->Curr->getX() - v.X()) <= 1 ||
		std::abs(tmp->NextNode->Curr->getY() - v.Y()) <= 1))
		{
			if(tmp->NextNode->NextNode != NULL)
			{
				tmp->NextNode = new Node(*tmp->NextNode->NextNode);
				//delete tmp->Curr;
			}
			else
				tmp->NextNode = NULL;			
		}
		else
			tmp = tmp->NextNode;
	}
}