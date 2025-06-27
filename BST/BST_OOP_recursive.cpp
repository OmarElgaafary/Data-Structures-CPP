#include <iostream>
#include <queue>
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class BST
{
private:
    Node* root = nullptr;
public:

    Node* get_root()
    {
        return root;
    }

    void Find(int data)
    {
        std::cout << (Search(root, data) ? "[Found]\n" : "[Not Found]\n");
    }

    void create_node(int data)
    {
        root = insert_node(root, data);
    }


    Node* insert_node(Node* root, int data)
    {
        Node* new_node = new Node{data, nullptr, nullptr};
        if (root == nullptr)
        {
            root = new_node;
        }

        else if (new_node->data == root->data)
            return root; // no duplicates
        
        else if (new_node->data < root->data)
        {
            root->left = insert_node(root->left, data);
        }

        else
        {
            root->right = insert_node(root->right, data);
        }

        return root;
    }

    bool Search(Node* root ,int data)
    {
        Node* tmp = root;
        if (root == nullptr) return false;
   
        else if (data == root->data)
            return true;
        else if (data < root->data)
            return Search(root->left, data);
        else if (data > root->data)
            return Search(root->right, data);
    }

    void breadth_first_search(Node* root)
    {
        std::queue<Node*> Queue;
        if (root == nullptr) return;
        Queue.push(root);

        while (!Queue.empty())
        {
            Node* front = Queue.front();
            std::cout << front->data << " ";
            if (front->left != nullptr) Queue.push(front->left);
            if (front->right != nullptr) Queue.push(front->right);
            Queue.pop();
        }


    }

    void depth_first_search_preorder(Node* root)
    {
        if (root == nullptr) return;

        std::cout << root->data << " ";
        depth_first_search_preorder(root->left);
        depth_first_search_preorder(root->right);

    }

    void depth_first_search_inorder(Node* root)
    {
        if (root == nullptr) return;

        depth_first_search_inorder(root->left);
        std::cout << root->data << " ";
        depth_first_search_inorder(root->right);

    }

    void depth_first_search_postorder(Node* root)
    {
        if (root == nullptr) return;

        depth_first_search_postorder(root->left);
        depth_first_search_postorder(root->right);
        std::cout << root->data << " ";

    }

    
    
};




int main()
{
    BST my_bst;
    my_bst.create_node(16);
    my_bst.create_node(7);
    my_bst.create_node(21);
    my_bst.create_node(15);
    my_bst.create_node(17);
    my_bst.create_node(32);

    my_bst.depth_first_search_postorder(my_bst.get_root());

}
