#include <iostream>
using namespace std;


struct node {
	int data;
	node* next;
};

struct dnode {
	int data;
	dnode* next;
	dnode* prev;
};

node* newNode(int data) {
	node* myNewNode = new node;

	myNewNode->data = data;
	myNewNode->next = NULL;

	return myNewNode;
}

dnode* newDoubleNode(int data) {
	dnode* new_node = new dnode;
	new_node->data = data;
	new_node->next = new_node->prev = NULL;

	return new_node;
}

dnode* newCircularDoubleNode(int data) {
	dnode* new_node = new dnode;
	new_node->data = data;
	new_node->next = new_node->prev = new_node;

	return new_node;
}

void printList(node* list) {
	if (list == NULL)
		cout << "list is empty.\n";
	else {
		while (list != NULL) {
			cout << list->data;
			if (list->next != NULL) cout << ", ";
			list = list->next;
		}

		cout << endl;

	}
}

void insertAtBeginning(node*& list, int data) {
	node* new_node = newNode(data);

	new_node->next = list;
	list = new_node;
}

void insertAtEnd(node*& list, int data) {
	node* new_node = newNode(data);

	if (list == NULL)
		list = new_node;
	else {
		node* tmp = list;

		while (tmp->next != NULL) {
			tmp = tmp->next;
		}

		tmp->next = new_node;
	}

}

void deleteFromBeginning(node*& list) {
	if (list == NULL)
		cout << "list is empty.\n";
	else {
		if (list->next == NULL) {
			delete list;
			list = NULL;
		}
		else {
			node* tmp = list;
			list = list->next;
			delete tmp;
		}
	}
}

void destroyList(node*& list) {
	if (list == NULL)
		cout << "list is empty.\n";
	else {
		node* tmp = list;
		while (list != NULL) {
			list = list->next;
			delete tmp;
			tmp = list;
		}
	}
}

void insertAtIndex(node*& list, int k, int data) {
	if (k < 0) {
		cout << "error: index cannot be negative.\n";
		return;
	}

	if (k == 0) {
		insertAtBeginning(list, data);
		return;
	}

	node* tmp = list;
	int index = 0;

	while (tmp != NULL && index < k - 1) {
		tmp = tmp->next;
		index++;
	}

	if (tmp == NULL) {
		cout << "error: index out of bounds.\n";
		return;
	}

	node* new_node = newNode(data);
	new_node->next = tmp->next;
	tmp->next = new_node;
	
}

void deleteFirstNode(node*& list) {
	if (list == NULL)
		cout << "list is empty.\n";
	else {
		node* tmp = list;
		list = list->next;
		delete tmp;
	}
}

void concatenateLists(node* l1, node*& l2) {
	while (l1->next != NULL) l1 = l1->next;
	l1->next = l2;
	l2 = NULL;
}

int linearLinkedSearch(node* list, int t) {
	int i = 0;
	while (list != NULL) {
		if (list->data == t)
			return i;
		list = list->next;
		i++;
	}

	return -1;
}

void insertCircularLinkedListNode(node*& list, int data) {
	node* new_node = new node;
	new_node->data = data;
	new_node->next = new_node;

	if (list == NULL)
	{
		list = new_node;
		return;
	}

	node* first_node = list;
	node* tmp = list;

	while (tmp->next != first_node) tmp = tmp->next;

	tmp->next = new_node;
	new_node->next = first_node;
}

void printCircularLinkedList(node* list) {
	if (list == NULL)
		cout << "list is empty.\n";
	else {
		node* tmp = list;

		do {
			cout << list->data;
			if (list->next != tmp) cout << ", ";
			list = list->next;
		} while (list != tmp);
	}
}

void insertDoubleBeginning(dnode*& list, int data) {
	dnode* new_node = newDoubleNode(data);

	if (list == NULL) {
		list = new_node;
	}
	else {
		new_node->next = list;
		list->prev = new_node;
		list = new_node;
	}
}

void insertDoubleEnd(dnode*& list, int data) {
	dnode* new_node = newDoubleNode(data);

	if (list == NULL) {
		list = new_node;
	}
	else {
		dnode* tmp = list;

		while (tmp->next != NULL) tmp = tmp->next;

		tmp->next = new_node;
		new_node->prev = tmp;

	}
}

void insertDoublePosition(dnode*& list, int data, int k) {
	if (k < 0) {
		cout << "error: kth position cannot be negative.\n";
		return;
	}

	if (k == 0) {
		return insertDoubleBeginning(list, data);
	}
	else {
		dnode* new_node = newDoubleNode(data);
		dnode* tmp = list;
		int index = 0;

		while (tmp != NULL && index < k - 1) {
			++index;
			tmp = tmp->next;
		}

		if (tmp == NULL) {
			cout << "error: index out of bounds.\n";
			return;
		}

		new_node->next = tmp->next;
		new_node->prev = tmp;

		if (tmp->next != NULL)
			tmp->next->prev = new_node;

		tmp->next = new_node;
	}
}

void deleteDoublePositon(dnode*& list, int k) {
	if (list == NULL) {
		cout << "list is empty.\n";
		return;
	}

	if (k < 0) {
		cout << "error: invalid input position k cannot be negative.\n";
		return;
	}

	dnode* tmp = list;

	if (k == 0) {
		list = tmp->next;
		list->prev = NULL;
		delete tmp;
		return;
	}
	else {
		int index = 0;

		while (tmp != NULL && index < k) {
			++index;
			tmp = tmp->next;
		}

		if (tmp == NULL) {
			cout << "error: index out of bounds.\n";
			return;
		}

		(tmp->prev)->next = tmp->next;

		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;

		delete tmp;
	}
}

void printDoubleLinked(dnode* list) {
	if (list == NULL) {
		cout << "list is empty.\n";
	}
	else {
		while (list != NULL) {
			cout << list->data;
			if (list->next != NULL) cout << ", ";
			list = list->next;
		}
	}
}

void insertAtBeginningDoubleCircular(dnode*& list, int data) {
	dnode* new_node = newCircularDoubleNode(data);

	if (list == NULL) {
		list = new_node;
	}
	else {
		new_node->next = list;
		new_node->prev = list->prev;
		list->prev = new_node;
		(new_node->prev)->next = new_node;

		list = new_node;
	}
}

void printDoublyCircular(dnode* list) {
	if (list == NULL) {
		cout << "list is empty.\n";
	}
	else {
		dnode* first_node = list;
		do {
			cout << list->data;
			if (list->next != first_node) cout << ", ";
			list = list->next;
		} while (list != first_node);
	}
}

bool checkSortedDoubleCircular(dnode* list) {
	if (list == NULL) {
		cout << "list is empty.\n";
		return true;
	}
	else {
		dnode* first_node = list;
		int not_sorted_flag = 0;

		do {
			if (list->data > list->next->data) {
				return false;
			}

			list = list->next;
		} while (list->next != first_node);

		return true;
	}
}

int main() {
	dnode* list = NULL;

	for (int i = 10; i > 0; i--) insertAtBeginningDoubleCircular(list, i);


	printDoublyCircular(list);


	cout << endl;

	if (checkSortedDoubleCircular(list))
		cout << "list is not sorted";
	else
		cout << "list is sorted";
}
