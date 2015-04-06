#include <iostream>
#include "polygon.h"
#include "point.h"
#include "circle.h"
#include "rectangle.h"
#include "shapelist.h"
using namespace std;

int main()
{
	ShapeList list;
  Vertex varr[] = { Vertex(0,0), Vertex(10,0),
                    Vertex(5,2), Vertex(5,5) };
  list.add( Polygon( 1, 4, varr, 4 ) );
  list.add( Rectangle( 4, 10, 2, 4) );
  list.add( Circle( 5,5, 3)  );
  list.add( Point( 6, 7, 1 ) );

  list.print();
  cout << " Totalyta: " << list.area() << endl;

  ShapeList list2(list);
  list2.print();
  cout << " Totalyta: " << list2.area() << endl;
  list.remove( Vertex(5,5) );
  list.print();
  cout << " Totalyta: " << list.area() << endl;
  list2.print();
  cout << " Totalyta: " << list2.area() << endl;  

  return 0;
}