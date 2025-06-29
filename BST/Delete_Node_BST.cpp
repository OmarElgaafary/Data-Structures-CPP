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
