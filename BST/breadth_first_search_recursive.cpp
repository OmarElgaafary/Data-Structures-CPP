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
