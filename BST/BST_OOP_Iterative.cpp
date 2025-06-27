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
    //destructor
    ~BST() { destroy_trees(root); };

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
            if (tmp->data == new_node->data)
            {
                delete new_node;
                return;
            }
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

        if (tmp == nullptr)
            return false;
  
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

    void destroy_trees(Node* root)
    {
        if (root != nullptr)
        {
            destroy_trees(root->left);
            destroy_trees(root->right);
            delete root;
        }
    }

    int find_min()
    {
        if (root == nullptr) return -1;

        Node* tmp = root;

        while (tmp->left != nullptr)
        {
            tmp = tmp->left;
        }

        return tmp->data;
  
    }

    int find_max()
    {
        if (root == nullptr) return -1;

        Node* tmp = root;

        while (tmp->right != nullptr)
        {
            tmp = tmp->right;
        }

        return tmp->data;
    }
};



int main()
{
    BST my_bst;
    my_bst.insert_node(14);
    my_bst.insert_node(3);
    my_bst.insert_node(26);
    my_bst.insert_node(2);
    my_bst.insert_node(34);
    


    std::cout << my_bst.find_max();
    /*std::cout << (my_bst.Search(26) ? "[Found]\n" : "[Not Found]\n");*/

}
