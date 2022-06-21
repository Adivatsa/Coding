void invert(Node* root)
  {
      if(root==NULL)
        return;
        
        //left and right jao
        //ane ke baad dono links ko swap kara do
        invert(root->left);
        invert(root->right);
        
        //Ab swap karea do links ko
        Node* temp=root->left;
        root->left=root->right;
        root->right=temp;
        
  }
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL)
            return;
        invert(node);
    }


    //Leetcode

        void solve(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        //Left and right recursive calls
        solve(root->left);
        solve(root->right);
        
        //aane ke baad swap kara do links ko
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        solve(root);
        return root;
        
    }