#include <iostream>
#include <climits>
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class BST
{
private:
    Node* bst_root = nullptr;
public:

    void create_node(int data)
    {
        bst_root = insert_node(bst_root, data);
    }

    Node* insert_node(Node* root, int data)
    {
        Node* new_node = new Node{data, nullptr, nullptr};
        if (root == nullptr)
        {
            root = new_node;
            return root;

        }

        else if (root->data == data)
            return root;

        else if (data < root->data)
        {
            root->left = insert_node(root->left, data);
        }

        else if (data > root->data)
        {
            root->right = insert_node(root->right, data);
        }

        return root;
    }

    bool validate(Node* root, int min_value, int max_value)
    {
        if (root == nullptr) return true;

        if (!(root->data > min_value && root->data < max_value))
            return false;

        return validate(root->left, min_value, root->data) &&
               validate(root->right, root->data, max_value);
    }

    Node* get_root()
    {
        return bst_root;
    }
        

};


int main()
{
    BST my_bst;
    my_bst.create_node(25);
    my_bst.create_node(16);
    my_bst.create_node(32);
    my_bst.create_node(5);
    my_bst.create_node(19);
    my_bst.create_node(27);
    my_bst.create_node(39);

    std::cout << (my_bst.validate(my_bst.get_root(), INT_MIN, INT_MAX) ? "[Valid BST]\n" : "[Invalid BST]\n");
}
