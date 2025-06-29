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

    Node* find_max(Node* root)
    {
        if (root->right == nullptr) return root;
        return find_max(root->right);
    }

    Node* Delete(Node* root, int data)
    {
        if (root == nullptr) return nullptr;
        else if (data < root->data)
            root->left = Delete(root->left, data);
        else if (data > root->data)
            root->right = Delete(root->right, data);
        else // data found
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
            }
            else if (root->right == nullptr)
            {
                Node* tmp = root;
                root = root->left;
                delete tmp;
            }
            else if (root->left == nullptr)
            {
                Node* tmp = root;
                root = root->right;
                delete tmp;
            }
            else
            {
                Node* tmp = find_max(root->left);
                root->data = tmp->data;
                root->left = Delete(root->left, tmp->data);
            }

        }
        return root;
    }

    void depth_preorder(Node* root)
    {
        if (root == nullptr) return;
     
        std::cout << root->data << " ";
        depth_preorder(root->left);
        depth_preorder(root->right);
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

    my_bst.depth_preorder(my_bst.get_root());

    std::cout << "\n\n--------------------\n\n";

    my_bst.Delete(my_bst.get_root(), 32);

    my_bst.depth_preorder(my_bst.get_root());

}
