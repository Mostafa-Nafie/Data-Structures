#include<iostream>
#include<vector>

class PriorityQueue
{
private:
	std::vector<int> arr;
	int Parent(int i)
	{
		return (i - 1) / 2;
	}
	int Left(int i)
	{
		return i * 2 + 1;
	}
	int Right(int i)
	{
		return i * 2 + 2;
	}
	void swapelements(int* a, int* b) 
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	void bubbleDown(int i)
	{
		int left = Left(i);
		int right = Right(i);
		int smallest = i;
		if (left < size() && arr[left] < arr[smallest])
			smallest = left;
		if (right < size() && arr[right] < arr[smallest])
			smallest = right;
		if (smallest != i)
		{
			swapelements(&arr[i], &arr[smallest]);
			bubbleDown(smallest);
		}
	}

	void bubbleUp(int i)
	{
		if (arr[Parent(i)] > arr[i])
		{
			swapelements(&arr[i], &arr[Parent(i)]);
			bubbleUp(Parent(i));
		}
	}

public:
	unsigned int size() { return arr.size(); }
	bool isEmpty() { return size() == 0; }
	void add(int value)
	{
		arr.push_back(value);
		int index = size() - 1;
		bubbleUp(index);
	}
	void pop()
	{
		arr[0] = arr.back();
		arr.pop_back();
		bubbleDown(0);
	}
	int search(int value)
	{
		for (int i = 0; i < size(); i++)
			if (arr[i] == value)
				return i;
		return -1;
	}
	void remove(int value)
	{
		int index = search(value);
		if (index >= 0)
		{
			swapelements(&arr[index], &arr[size() - 1]);
			arr.pop_back();
			int x = arr[index];
			bubbleUp(index);
			if (search(x) == index)
				bubbleDown(index);
		}
		else
			std::cout << "This value isn't found" << std::endl;
	}

	void print()
	{
		for (int i = 0; i < size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
};

void main()
{
	PriorityQueue x;
	x.add(5);
	x.add(11);
	x.add(12);
	x.add(6);
	x.print();
	x.add(14);
	x.add(7);
	x.add(8);
	x.print();
	x.add(19);
	x.add(13);
	x.add(10);
	x.add(1);
	x.print();

	x.pop();
	x.print();
	x.pop();
	x.print();
	x.remove(10);
	x.print();
	x.remove(48);

	std::cin.get();
}