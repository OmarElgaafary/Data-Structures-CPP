
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST
{
private:
    Node* root = nullptr;

public:
    void insert_node(int data)
    {
        Node* new_node = new Node{ data, nullptr, nullptr };
        if (root == nullptr)
        {
            root = new_node;
            return;
        }

        Node* tmp = root;
        while (tmp != nullptr)
        {
            if (tmp->data == new_node->data) // no dulpicates.
                return;
            else if (new_node->data < tmp->data && tmp->left == nullptr)
            {
                tmp->left = new_node;
                break;
            }
            else if (new_node->data < tmp->data)
            {
                tmp = tmp->left;
            }
            else if (new_node->data > tmp->data && tmp->right == nullptr)
            {
                tmp->right = new_node;
                break;
            }
            else
            {
                tmp = tmp->right;
            }
        }

    }

    bool Search(int data)
    {
        Node* tmp = root;
        if (tmp == nullptr) return false;
        else
        {
            while (tmp != nullptr)
            {
                if (tmp->data == data)
                    return true;
                else if (data < tmp->data)
                    tmp = tmp->left;
                else if (data > tmp->data)
                    tmp = tmp->right;

            }
            return false;
        }

        
        
    }
};



int main()
{
    BST my_bst;
    my_bst.insert_node(14);
    my_bst.insert_node(3);
    my_bst.insert_node(26);
    my_bst.insert_node(1);
    my_bst.insert_node(34);

    std::cout << my_bst.Search(26);

}
