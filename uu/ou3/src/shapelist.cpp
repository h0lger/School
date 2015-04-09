#include "shapelist.h"

ShapeList::ShapeList()
{	
	_node = NULL;
}

ShapeList::ShapeList(const ShapeList &s)
{
	_node = new Node(*s._node); //skapar en kopia	av hela kedjan	
}

ShapeList::~ShapeList()
{	
	delete _node;
}

void ShapeList::add(const Shape &s)
{
	_node = new Node(*s.clone(), _node);	
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
	Node *prev = NULL;
	Node *current = _node;
	Node *next = current->NextNode;	
	
	while(current != NULL)
	{
		if(candidateRemove(current, v))
		{
			if(prev != NULL)
                prev->NextNode = new Node(*next);
			else
			{
                _node = next;
				prev = _node;
			}
            next = prev->NextNode->NextNode;
            delete current;
		}
		else
			prev = current;
		
		current = next;
		if(current != NULL)
			next = current->NextNode;
	}	
}

bool ShapeList::candidateRemove(Node *n, const Vertex &v)
{
	if(n != NULL && (std::abs(n->Curr->getX() - v.X()) < 1 ||
		std::abs(n->Curr->getY() - v.Y()) < 1))
		{
			return true; //ska tas bort
		}
		else
			return false;
}
