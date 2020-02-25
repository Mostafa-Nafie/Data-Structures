#include<iostream>
#include<queue>

struct BSTNode {
	int key;
	int value;
	BSTNode* left;
	BSTNode* right;

	BSTNode(int key,int value)
	{
		this->key = key;
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
};

class BST {
private:
	BSTNode* root;
	int size;
public:
	BST()
	{
		root = nullptr;
		size = 0;
	}

	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size == 0;
	}




	BSTNode* search(BSTNode* subtree, int target)
	{
		if (subtree == nullptr)
			return nullptr;
		else if (subtree->key < target)
			return search(subtree->right, target);
		else if (subtree->key > target)
			return search(subtree->left, target);
		else
			return subtree;
	}

	
	
	
	bool hasKey(int key)
	{
		return search(root, key) != nullptr;
	}




	void add(int key,int value)
	{
		if (root == nullptr)
		{
			root = new BSTNode(key, value);
			size++;
		}
		else
		{
			BSTNode* node = search(root, key);
			if (node != nullptr)
			{
				node->value = value;
			}
			else
			{
				root = insert(root, key, value);
				size++;
			}
		}
	}



	BSTNode* insert(BSTNode* subtree, int key, int value)
	{
		if (subtree == nullptr)
			subtree = new BSTNode(key, value);
		else if (key < subtree->key)
			subtree->left = insert(subtree->left, key, value);
		else
			subtree->right = insert(subtree->right, key, value);
		return subtree;
	}



	BSTNode* getMin(BSTNode* subtree)
	{
		while (subtree->left != nullptr)
			subtree = subtree->left;
		return subtree;
	}

	BSTNode* getMax(BSTNode* subtree)
	{
		while (subtree->right != nullptr)
			subtree = subtree->right;
		return subtree;
	}



	void remove(int target)
	{
		BSTNode* node = search(root, target);
		if (node == nullptr)
			std::cout << "Invalid key" << std::endl;
		else
		{
			root = removeHelper(root, target);
			size--;
		}
	}
	
	BSTNode* removeHelper(BSTNode* subtree, int target)
	{
		if (target < subtree->key)
		{
			subtree->left = removeHelper(subtree->left, target);
			return subtree;
		}
		else if (target > subtree->key)
		{
			subtree->right = removeHelper(subtree->right, target);
			return subtree;
		}
		else
		{
			if (subtree->left == nullptr && subtree->right == nullptr)
			{
				delete subtree;
				return nullptr;
			}
			else if (subtree->left == nullptr || subtree->right == nullptr)
				if (subtree->left == nullptr)
				{
					BSTNode* next = subtree->right;
					delete subtree;
					return next;
				}
				else
				{
					BSTNode* next = subtree->left;
					delete subtree;
					return next;
				}
			else
			{
				BSTNode* successor = getMin(subtree->right);
				subtree->key = successor->key;
				subtree->value = successor->value;
				subtree->right = removeHelper(subtree->right, successor->key);
				return subtree;
			}
		}
	}


	void levelorder(BSTNode* subtree)
	{
		std::queue<BSTNode*> q;
		if (subtree != nullptr)
		{
			q.push(subtree);
		}
		else
			std::cout << "NULL " << std::endl;
		while(1)
		{
			int nodecount = q.size();
			if (nodecount == 0)
				break;
			while (nodecount > 0)
			{
				BSTNode* temp = q.front();
				q.pop();
				if (temp)
				{
					std::cout << temp->key << " ";
					q.push(temp->left);
					q.push(temp->right);
				}
				else
					std::cout << "NULL ";
				nodecount--;
			}
			std::cout << std::endl;
		}
	}

	void print()
	{
		std::cout << "The tree is : " << std::endl;
		levelorder(root);
	}


};


void main() {
	BST x;
	x.add(3, 39);
	x.add(5, 30);
	x.add(2, 29);
	x.print();
	x.add(1, 42);
	x.add(4, 23);
	x.add(6, 24);
	x.print();
	x.add(0, 43);
	x.print();
	x.remove(3);
	x.print();
	std::cin.get();
}