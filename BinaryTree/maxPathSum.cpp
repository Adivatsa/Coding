int solve(TreeNode* root, int &res)
    {
        //In this we will calculate the sum from left and right
        //Maximum will be returned from left or right with adding root value
        //if value got is negative then start from that node only
        //It might be possible that it will be required max path sum so compare it.
        
        //Base condtion
        if(root==NULL)
            return 0;
        
        int l=solve(root->left, res);
        int r=solve(root->right,res);
        
        //get the desired result
        int temp=max(max(l,r)+root->val , root->val);
        
        int ans=max( l+r+(root->val), temp);
        
        res=max(res, ans);
        
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        
        //In this question we have find out the maximum sum calculted from path
        //There can be many path and we have to select with maximum one
        //a path sum will be stored can be used further
        int res=INT_MIN;
        
        solve(root,res);
        
        return res;
        
    }