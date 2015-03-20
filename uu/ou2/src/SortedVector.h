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
	int itemPos; //håller reda på sista "verkliga" elementet i vektorn
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
	T tmp(a);
	a = b;
	b = tmp;
}

template<class T, int size> void SortedVector<T, size>::sort()
{
	//implementation av instickningssortering	
	for(int top = 1; top < itemPos; top++)
	{
		for(int search = top-1;search >= 0 && vec[search+1] < vec[search];search--)
			{
				swap(vec[search], vec[search+1]);
			}
	}
}

template<class T, int size> bool SortedVector<T, size>::add(const T& v)
{
	if(itemPos + 1 < size)
	{
		vec[itemPos++] = T(v);
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
	int median = (itemPos - 1) / 2; //egentligen left + (right-left)/2
	return vec[median];
}

template<class T, int size> void SortedVector<T, size>::removeLarger(const T &v)
{	
	int j = 0; //sista positionen som ska behållas
	
	//gå igenom vektorn
	for(int i = 0;i < itemPos;i++)
	{		
		if(vec[i] > v)
		{
			j = itemPos - 1;
			break; //gå ur loopen när vi hittat
		}
	}
	
	//rensa alla större än v
	for(int i = j;i < itemPos;i++)
	{
		vec[i] = 0;
	}

	//sätt om positionen
	itemPos = j;
}


#endif