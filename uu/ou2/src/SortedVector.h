#ifndef SORTED_VECTOR_H
#include <iostream>
using namespace std;

template <class T, int size> class SortedVector
{
	
public:
	SortedVector(); //konstruktor	
	bool add(const T& v); //lägg till ett element
	T& median(); //returnerar elementet i mitten av vektorn
	void removeLarger(const T& v); //ta bort alla element större än v
	void print(ostream &os); //skriv ut alla element i vektorn
	
private:
	T vec[size];	
	int itemPos; //håller reda på sista elementet i vektorn
	void sort(); //sortera vektorn
	void swap(T& a, T& b); //byta plats på objekt
	
};

//implementationer
template<class T, int size> SortedVector<T, size>::SortedVector()
{	
	itemPos = 0;
}

template<class T, int size> void SortedVector<T, size>::swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T, int size> void SortedVector<T, size>::sort()
{
	//Implementation av bubble sort
	for(int top = itemPos - 1;top > 0;top--)
	{
		for(int i = 0;i < top;i++)
		{
				if(vec[i+1] < vec[i])
					swap(vec[i], vec[i+1]);
		}
	}
}

template<class T, int size> bool SortedVector<T, size>::add(const T& v)
{
	if(itemPos + 1 < size)
	{
		vec[itemPos++] = v;
		sort(); //sortera vektorn
		return true;
	}
	else
		return false;
}

template<class T, int size> void SortedVector<T, size>::print(ostream &os)
{	
	for(int i = 0;i < itemPos;i++)
	{
		cout << i << ": " << vec[i] << endl;		
	}	
}

template<class T, int size> T& SortedVector<T, size>::median()
{
	
}


#endif