#include <iostream>


struct Node
{
	int data;
	Node* link;
};

class stack_linked
{
private:
	Node* linked_top = nullptr;
public:

	void push(int x)
	{
		Node* tmp = new Node();
		tmp->data = x;
		tmp->link = linked_top;
		linked_top = tmp;
	}

	void pop()
	{
		Node* tmp = linked_top;
		linked_top = linked_top->link;
		delete tmp;
		
	}

	int get_top_data()
	{
		return linked_top->data;
	}

	bool is_empty()
	{
		if (linked_top == nullptr)
			return true;
		else
			return false;
	}
	
	void print_stack(Node* node)
	{
		if (node == nullptr) return;
		print_stack(node->link);
		std::cout << node->data << " ";

	}

	Node* get_top_address()
	{
		return linked_top;
	}


};

int main()
{
	stack_linked my_stack;
	my_stack.push(5);
	my_stack.push(10);
	my_stack.push(15);
	my_stack.push(20);
	my_stack.push(25);
	my_stack.push(30);

	my_stack.print_stack(my_stack.get_top_address());

	my_stack.pop();
	my_stack.pop();

	std::cout << "\n\n --------------------------- \n\n";

	my_stack.print_stack(my_stack.get_top_address());
}
