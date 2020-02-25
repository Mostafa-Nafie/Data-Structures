#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

template<typename T>
class Node
{
private:
	T data;
	Node<T>* next;
	Node<T>* previous;
public:
	Node(T data)
	{
		this->data = data;
		next = nullptr;
		previous = nullptr;
	}
	void setData(T data)
	{
		this->data = data;
	}
	void setNext(Node<T>* Next)
	{
		this->next = Next;
	}
	void setPrevious(Node<T>* Previous)
	{
		this->previous = Previous;
	}
	T getData()
	{
		return data;
	}
	Node<T>* getNext()
	{
		return next;
	}
	Node<T>* getPrevious()
	{
		return previous;
	}

};


template<typename T>
class DoublyLinkedList
{
private:
	int size;
	Node<T>* head;
	Node<T>* tail;
public:
	DoublyLinkedList()
	{
		size = 0;
		head = nullptr;
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size == 0;
	}
	void addHead(T data)
	{
		Node<T>* temp = new Node<T>(data);
		if (isEmpty())
			head = tail = temp;
		else
		{
			head->setPrevious(temp);
			temp->setNext(head);
			head = temp;
		}
		size++;
	}
	void addTail(T data)
	{
		Node<T>* temp = new Node<T>(data);
		if (isEmpty())
			head = tail = temp;
		else
		{
			tail->setNext(temp);
			temp->setPrevious(tail);
			tail = temp;
		}
		size++;
	}
	void print()
	{
		if (isEmpty())
			std::cout << "The list is empty " << std::endl;
		else
		{
			Node<T>* current = head;
					while (current->getNext() != nullptr)
					{
						std::cout << current->getData() <<" <=> ";
						current = current->getNext();
					}
					std::cout << current->getData() << std::endl;
		}
	}
	void removeHead()
	{
		remove(head->getData());
	}
	void remove(T data)
	{
		if (head == nullptr && tail == nullptr)
			std::cout << "The list is empty" << std::endl;
		else
		{
			size--;
			Node<T>* current = head;
			while (current->getData() != data)
				current = current->getNext();
			if (current == head)
			{
				head = head->getNext();
				if (isEmpty())
					tail = nullptr;
				else
					current->getNext()->setPrevious(current->getPrevious());
				
			}
			else if (current == tail)
			{
				tail = tail->getPrevious();
				if (isEmpty())
					head = nullptr;
				else
					current->getPrevious()->setNext(current->getNext());
			}
			else
			{
				current->getPrevious()->setNext(current->getNext());
				current->getNext()->setPrevious(current->getPrevious());
			}
			delete current;
		}
	}
	bool serach(T value)
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
	T peakHead()
	{
		if (isEmpty())
			std::cout << "The List is empty" << std::endl;
		else
			return head->getData();
	}
};

template<typename T>
class Stack
{
private:
	DoublyLinkedList<T> stack;
public:
	Stack()
	{
	}
	void push(T data)
	{
		stack.addHead(data);
	}
	T pop() 
	{
		T temp = stack.peakHead();
		stack.removeHead();
		return temp;
	}
	int size()
	{
		return stack.size();
	}
	bool isEmpty()
	{
		return stack.isEmpty();
	}
	T peak()
	{
		return stack.peakHead();
	}
	void print()
	{
		stack.print();
	}
};

void infixTo(const char* exp)
{
	std::unordered_map<char, int> prec =
	{
		{'^', 4},
		{'*', 3}, {'/', 3 },
		{'+', 2}, {'-' ,2 },
		{'(', 1}
	};

	Stack<char> opStack;
	std::vector<int> postfixlist;
	std::vector<char> tokenlist;
	std::vector<char> nums;
	for (int i = 0; i < 10; i++)
		nums.push_back(i + 48);
	for (int i = 0; exp[i] != '\0'; i+= 2)
		if (std::find(nums.begin(), nums.end(), exp[i]) != nums.end())
			postfixlist.push_back(exp[i]);
		else if (exp[i] == '(')
			opStack.push(exp[i]);
		else if (exp[i] == ')')
		{
			char toptoken = opStack.pop();
			while (toptoken != '(')
			{
				postfixlist.push_back(toptoken);
				toptoken = opStack.pop();
			}
		}
		else
		{
			while (!opStack.isEmpty() && prec[opStack.peak()] >= prec[exp[i]])
				postfixlist.push_back(opStack.pop());
			opStack.push(exp[i]);
		}
	while (!opStack.isEmpty())
		postfixlist.push_back(opStack.pop());
	for (int i = 0; i < postfixlist.size(); i++)
	{
		std::cout << (char)postfixlist[i] << " ";
	}

}



void main()
{

	DoublyLinkedList<int> x;
	infixTo("2 + 5 * 7 ^ 9 / 8 - 1");
	std::cin.get();

}