Node* find_min(Node* root)
{
    if (root->left == nullptr) return root;
    return find_min(root->left);
}

Node* find_max(Node* root)
 {
     if (root->right == nullptr) return root;
     return find_max(root->right);
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
