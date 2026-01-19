#include <iostream>

//#define MAIN

class Tree 
{
public:
	struct Node 
	{
		int value;
		Node* parent, * left, * right;
	};
private:
	Node* root;
public:
	Tree();
	~Tree();
	void print(Node* node);
	Node* search(Node* node, int x);
	Node* min(Node* node);
	Node* max(Node* node);
	Node* prev(Node* node);
	Node* next(Node* node);
	void Insert(Node* node);
	void Delete(Node* node = nullptr);
	Node* GetRoot();
};

Tree::Tree() 
{
	root = nullptr;
}
Tree::~Tree()
{
	Delete();
}
void Tree::print(Node* node)
{
	if (node != nullptr) 
	{
		print(node->left);
		std::cout << node->value << " ";
		print(node->right);
	}
}
Tree::Node* Tree::search(Node* node, int x)
{
	while (node != nullptr and x != node->value) 
	{
		if (x < node->value)
		{
			node = node->left;
		}
		else 
		{
			node = node->right;
		}
	}
	return node;
}
Tree::Node* Tree::min(Node* node)
{
	if (node != nullptr) 
	{
		while (node->left != nullptr) 
		{
			node = node->left;
		}
	}
	return node;
}
Tree::Node* Tree::max(Node* node) 
{
	if (node != nullptr)
	{
		while (node->right != nullptr)
		{
			node = node->right;
		}
	}
	return node;
}
Tree::Node* Tree::prev(Node* node)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			return max(node->left);
		}
		else
		{
			Node* copy = node;
			Node* temp_parent = node->parent;
			while (temp_parent != nullptr && temp_parent->left == copy)
			{
				copy = temp_parent;
				temp_parent = temp_parent->parent;
			}
			return temp_parent;
		}
	}
	return nullptr;
}
Tree::Node* Tree::next(Node* node) 
{
	if (node != nullptr)
	{
		if (node->right != nullptr)
		{
			return min(node->right);
		}
		else
		{
			Node* copy = node;
			Node* temp_parent = node->parent;
			while (temp_parent != nullptr and temp_parent->right == copy)
			{
				copy = temp_parent;
				temp_parent = temp_parent->parent;
			}
			return temp_parent;
		}
	}
}
void Tree::Insert(Node* node) 
{
	node->left = nullptr;
	node->right = nullptr;
	Node* temp_parent = nullptr;
	Node* place = root;
	while (place != nullptr) 
	{
		temp_parent = place;
		if (node->value < place->value) 
		{
			place = place->left;
		}
		else 
		{
			place = place->right;
		}
	}
	node->parent = temp_parent;
	if (temp_parent == nullptr) 
	{
		root = node;
	}
	else if (node->value < temp_parent->value)
	{
		temp_parent->left = node;
	}
	else
	{
		temp_parent->right = node;
	}
}
void Tree::Delete(Node* node) 
{
	if (node != nullptr) 
	{
		Node* elem, * temp;
		if (node->left == nullptr or node->right == nullptr) 
		{
			elem = node;
		}
		else 
		{
			elem = next(node);
		}
		if (elem->left != nullptr) 
		{
			temp = elem->left;
		}
		else 
		{
			temp = elem->right;
		}
		if (temp != nullptr) 
		{
			temp->parent = elem->parent;
		}
		if (elem->parent == nullptr) 
		{
			root = temp;
		}
		else if (elem->parent->left == elem) 
		{
			elem->parent->left = temp;
		}
		else
		{
			elem->parent->right = temp;
		}
		if (node != elem) 
		{
			node->value = elem->value;
		}
		delete elem;
	}
	else 
	{
		while (root != nullptr) 
		{
			Delete(root);
		}
	}
}
Tree::Node* Tree::GetRoot()
{
	return root;
}

#ifdef MAIN
int main()
{
	Tree t;
	for (int i = 0; i < 10; i++)
	{
		Tree::Node* elem = new Tree::Node;
		elem->value = rand() % 100;
		std::cout << elem->value << std::endl;
		t.Insert(elem);
	}
	t.print(t.GetRoot());
	std::cout << std::endl;
	t.Delete(t.GetRoot());
	t.print(t.GetRoot());
	std::cout << std::endl;
	t.Delete(t.search(t.GetRoot(), 64));
	t.print(t.GetRoot());
	std::cout << std::endl;
}
#endif //MAIN