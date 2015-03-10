#include <iostream>
using namespace std;
#include "polygon.h"
#include "SortedVector.h"

int main()
{
  SortedVector<Polygon,10> polygons;
  SortedVector<int,6> ints;

  ints.add( 3 );
	ints.add(10);
  ints.add( 1 );  
  ints.add( 6 );
	ints.print(cout);
	
	cout << "MEDIAN: " << ints.median() << endl;
	
	ints.removeLarger( 3 ); // 1 2 3
	ints.print(cout);
	
  Vertex varr[10];
  varr[0] = Vertex(0,0); 
  varr[1] = Vertex(10,0);
  varr[2] = Vertex(5,2);
  varr[3] = Vertex(5,5);
	Polygon pol(varr, 4);
	
  polygons.add(Polygon( varr, 4) );
  //cout << (Polygon(varr,4)).area() << endl;

  /*
	varr[0] = Vertex(0,0); 
  varr[1] = Vertex(25,8);
  varr[2] = Vertex(10,23);
  polygons.add( Polygon( varr, 3) );
  cout << (Polygon(varr,3)).area() << endl;
  varr[0] = Vertex(0,0); 
  varr[1] = Vertex(5,0);
  varr[2] = Vertex(5,3);
  varr[3] = Vertex(4,8);
  varr[4] = Vertex(2,10);
  polygons.add( Polygon( varr, 5) );
  cout << (Polygon(varr,5)).area() << endl;
  polygons.print(cout);
  ints.print(cout);

  cout << "MEDIAN: " << ints.median() << endl;
  cout << "MEDIAN: " << polygons.median() << endl;

  ints.add( 4);  // 1 3 4 6
  ints.add( 2);  // 1 2 3 4 6
  ints.add( 5);  // 1 2 3 4 5 6
  ints.removeLarger( 3 ); // 1 2 3
  cout << "MEDIAN: " << ints.median() << endl;*/
  
  return 0;
}