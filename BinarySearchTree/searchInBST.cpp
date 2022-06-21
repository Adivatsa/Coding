    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL)
            return root;
        if(root->val==val)
        {
            return root;
        }
        //if value is greater than root ka data then go to right otherwise left side
        if(val>root->val)
        {
            return searchBST(root->right,val);
        }
            return searchBST(root->left,val);
        
    }