
#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* create_node(int data)
{
    Node* new_node = new Node{data, NULL, NULL};
    return new_node;
}

Node* insert_node(Node* node, int data)
{
    if (node == NULL)
    {
        node = create_node(data);
    }
    else if (data <= node->data)
    {
        node->left = insert_node(node->left, data);
    }
    else 
    {
        node->right = insert_node(node->right, data);
    }

    return node;
}

bool bst_bool(Node* node, int data)
{
    if (node == NULL)
        return false;
    else if (node->data == data)
        return true;
    else if (data <= node->data)
    {
       return bst_bool(node->left, data);
    }
    else 
    {
       return bst_bool(node->right, data);
    }
}


int main()
{
    Node* bst_root = NULL;


    bst_root = insert_node(bst_root, 13);
    bst_root = insert_node(bst_root, 7);
    bst_root = insert_node(bst_root, 15);
    bst_root = insert_node(bst_root, 12);
    bst_root = insert_node(bst_root, 17);


    if(bst_bool(bst_root,12)) std::cout << "[Found]\n";
    else std::cout << "[Not Found]\n";
}
