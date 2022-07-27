    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        //check if any of tree exists then return other tree
        if(root1==NULL)
            return root2;
        if(root2==NULL)
            return root1;
        
        //we are shifting tree to tree 1 
        root1->val=root1->val + root2->val;
        
        //Recursive left and right call for tree 1 and return tree1 root
        root1->left=mergeTrees(root1->left, root2->left);
        root1->right=mergeTrees(root1->right, root2->right);
        return root1;  
    }