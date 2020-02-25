#include<iostream>

template<typename T>
class Node
{
private:
	T data;
	Node<T>* next;
public:
	Node(T data)
	{
		this->data = data;
		next = nullptr;
	}
	void setData(T data)
	{
		this->data = data;
	}
	void setNext(Node<T>* next)
	{
		this->next = next;
	}
	T getData()
	{
		return data;
	}
	Node<T>* getNext()
	{
		return next;
	}
	~Node()
	{
		NULL;
	}
};

template<typename T>
class SinglyLinkedList 
{
private:
	int size;
	Node<T>* head;
public:
	SinglyLinkedList()
	{
		size = 0;
		head = nullptr;
	}
	bool isEmpty()
	{
		return size == 0;
	}
	int getSize()
	{
		return size;
	}
	void add(T data)
	{
		Node<T>* temp = new Node<T>(data);
		temp->setNext(head);
		head = temp;
		size++;
	}
	bool search(T value)
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			if (current->getData() == value)
				return true;
			current = current->getNext();
		}
		return false;
	}

	void print()
	{
		Node<T>* current = head;
		while (current->getNext() != nullptr)
		{
			std::cout << current->getData() << " => ";
			current = current->getNext();
		}
		std::cout << current->getData() << std::endl;
	}

	void remove(T data)
	{
		Node<T>* previous = nullptr;
		Node<T>* current = head;
		while (current->getData() != data)
		{
			previous = current;
			current = current->getNext();
		}
		if (previous == nullptr)
			head = current->getNext();
		else
			previous->setNext(current->getNext());
		delete current;
	}

	void insert(int pos, T data)
	{
		if (pos == 0)
		{
			add(data);
			return;
		}
		Node<T>* temp = new Node<T>(data);
		Node<T>* current = head;
		for (int i = 0; i < pos - 1 ; i++)
			current = current->getNext();
		temp->setNext(current->getNext());
		current->setNext(temp);
	}

	~SinglyLinkedList()
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			head = head->getNext();
			delete current;
			current = head;
		}
	}
};


void main()
{
	SinglyLinkedList<int> x;
	x.add(2);
	x.add(3);
	x.add(5);
	x.print();
	x.insert(2, 8);
	x.print();
	x.insert(0, 10);
	x.print();
	x.remove(3);
	x.print();
	x.remove(5);
	x.print();


	SinglyLinkedList<char> y;
	y.add('m');
	y.add('o');
	y.add('a');
	y.add('z');
	y.print();
	y.remove('o');
	y.print();
	y.insert(2, 's');
	y.print();

	std::cin.get();
}