#include<iostream>
template<typename T>
class Queue
{
private:
	T arr[100];
	int head;
	int tail;
public:
	Queue()
	{
		head = -1;
		tail = -1;
	}
	bool isEmpty()
	{
		return size() == 0;
	}
	int size()
	{
		return tail - head + 1;
	}
	void enqueue(T data)
	{
		if (isEmpty())
			head = 0;
		arr[++tail] = data;
	}
	T dequeue()
	{
		return arr[head++];
	}
	void print()
	{
		if (isEmpty())
			std::cout << "The queue is empty" << std::endl;
		else
		{
			std::cout << "[";
			for (int i = head; i < tail; i++)
				std::cout << arr[i] << ", ";
			std::cout << arr[tail] << "]" << std::endl;
		}
	}

};

void main()
{
	Queue<int> x;
	x.enqueue(3);
	x.enqueue(40);
	x.enqueue(4);
	x.enqueue(8);
	x.enqueue(32);
	x.enqueue(18);
	x.print();
	x.dequeue();
	x.print();
	x.dequeue();
	x.print();
	std::cin.get();
}