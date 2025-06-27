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
