#include<iostream>
#include <stdexcept>
using namespace std;

template<class T>
class DynamicArray {
private:
	int capacity;
	int len;
	T* arr;
public:
	DynamicArray(int capacity)
	{
		this->capacity = capacity;
		len = 0;
		arr = new T[capacity];
	}
	int size()
	{
		return len;
	}
	bool isEmpty()
	{
		return len == 0;
	}
	void rangeCheck(int index)
	{
		if (index > len || index < 0)
			throw out_of_range("Index out of range");
	}
	T get(int index)
	{
		rangeCheck(index);
		return arr[index];
	}
	void set(int index, T element)
	{
		rangeCheck(index);
		arr[index] = element;
	}
	void clear()
	{
		for (int i = 0; i < len; i++)
			arr[i] = NULL;
		len = 0;
	}
	void add(T element)
	{
		if (len + 1 >= capacity)
		{
			capacity = capacity * 2;
			T* newarr = new T[capacity];
			for (int i = 0; i < len; i++)
				newarr[i] = arr[i];
			arr = newarr;
		}
		arr[len++] = element;
	}
	void removeat(int index)
	{
		T* newarr = new T[len - 1];
		rangeCheck(index);
		for (int i = 0, j = 0; i < len; i++, j++)
		{
			if (i == index)
				j--;
			else
				newarr[j] = arr[i];
		}
		capacity = --len;
		arr = newarr;
	}
	int indexof(T element)
	{
		for (int i = 0; i < len; i++)
			if (arr[i] == element)
				return i;
		return -1;
	}
	bool remove(T element)
	{
		int index = indexof(element);
		if (index == -1)
			return false;
		removeat(index);
		return true;
	}
	void print()
	{
		cout << "capacity = " << capacity << endl;
		cout << "length = " << len << endl;
		cout << "[";
		for (int i = 0; i < len - 1; i++)
			cout << arr[i] << ", ";
		cout << arr[len - 1] << "]" << endl;
	}
	~DynamicArray()
	{
		len = 0;
		capacity = 0;
		delete[]arr;
	}
};

void main()
{
	DynamicArray<int> x(3);
	x.add(2);
	x.print();
	x.add(5);
	x.print();
	x.add(6);
	x.print();
	x.add(53);
	x.print();
	x.remove(2);
	x.print();
	x.remove(53);
	x.print();
	x.clear();
	x.print();
	cin.get();
}