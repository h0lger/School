#ifndef SHAPE_h
class Shape
{
public:
	Shape();
	Shape(double x, double y);
	~Shape();
	double area();
	void print(); //skriver ut figuren (typ, position, storlek)
protected:
	double _x, _y;
};
#endif