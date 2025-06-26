#include <iostream>

struct Node {
	int data;
	Node* right;
	Node* left;
};

class BST
{
private:
	Node* root = nullptr;
public:

	void check(int data)
	{
		if (Search(root, data))
			std::cout << data << " is present in the BST.";
		else
			std::cout << data << " is not present in the BST.";
	}

	void create_node(int data)
	{
		root = insert_node(root, data);
	}

	Node* initalize_node(int data)
	{
		Node* new_node = new Node{ data, nullptr, nullptr };
		return new_node;
	}

	Node* insert_node(Node* nodeptr, int data)
	{
		if (nodeptr == nullptr)
		{
			nodeptr = initalize_node(data);
		}
		else if (data < nodeptr->data)
		{
			nodeptr->left = insert_node(nodeptr->left, data);
		}
		else
		{
			nodeptr->right = insert_node(nodeptr->right, data);
		}

		return nodeptr;
	}

	bool Search(Node* nodeptr, int data)
	{
		if (nodeptr == nullptr)
			return false;
		else if (nodeptr->data == data)
			return true;
		else if (data < nodeptr->data)
			return Search(nodeptr->left, data);
		else 
			return Search(nodeptr->right, data);
	}


};





int main()
{
	BST my_binary;
	my_binary.create_node(14);
	my_binary.create_node(7);
	my_binary.create_node(16);
	my_binary.create_node(12);
	my_binary.create_node(19);

	my_binary.check(7);


}
