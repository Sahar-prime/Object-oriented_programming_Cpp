#include <iostream>

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
	return 0;
}
Tree::Node* Tree::next(Node* node) 
{
	return 0;
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
	
}
Tree::Node* Tree::GetRoot()
{
	return root;
}

int main()
{
	Tree t;
	for (int i = 0; i < 10; i++)
	{
		Tree::Node* elem = new Tree::Node;
		elem->value = rand() % 100;
		t.Insert(elem);
	}
	t.print(t.GetRoot());
}