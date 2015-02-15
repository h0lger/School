#include <iostream>
#include "polygon.h"
using namespace std;


int main()
{
	Vertex vArr[] = { Vertex(0,0), Vertex(6,0), 
                    Vertex(6,6), Vertex(0,6) };

  Polygon pol(vArr, 4);
  cout << "num:  " <<  pol.numVertices() << endl;
  cout << "yta:  " <<  pol.area() << endl;
  cout << "minx: " <<  pol.minx() << endl;
  cout << "maxx: " <<  pol.maxx() << endl;
  cout << "miny: " <<  pol.miny() << endl;
  cout << "maxy: " <<  pol.maxy() << endl;

  pol.add( Vertex(-1,3) );
  cout << "num:  " <<  pol.numVertices() << endl;
  cout << "yta:  " <<  pol.area() << endl;
  cout << "minx: " <<  pol.minx() << endl;

  Polygon pol1;
  pol1.add( Vertex(0,0) );
  pol1.add( Vertex(3,3) );
  pol1.add( Vertex(3,0) );
  
  cout << "triangelyta: " << pol1.area() << endl;
	

	return 0;
}