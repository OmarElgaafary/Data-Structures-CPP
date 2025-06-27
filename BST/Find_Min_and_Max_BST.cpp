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
