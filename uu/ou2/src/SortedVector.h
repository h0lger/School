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
	T tmp = a;
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
	int median = (itemPos - 1) / 2; //egentligen left + (right-left)/2
	return vec[median];
}

template<class T, int size> void SortedVector<T, size>::removeLarger(const T &v)
{
	T tmp[size];
	int j = 0;
	//gå igenom vektorn
	for(int i = 0;i < itemPos;i++)
	{
		//om den är mindre så behåller vi den
		if(vec[i] <= v)
			tmp[j++] = vec[i];
	}
	
	//skiftar vector
	if(j > 0)
	{	
		*vec = *tmp;
		itemPos = j;
	}
}


#endif