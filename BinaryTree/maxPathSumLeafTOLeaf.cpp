    int solve(Node* root, int &res)
    {
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
            return root->data;
        
        
            
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
        if(root->left!=NULL && root->right!=NULL)
        {
            int temp=max(l,r)+root->data;
        
            int ans=l+r+root->data;
        
            res=max(res,ans);
        
            return temp;
        }
        if(root->left==NULL)
            return r+root->data;
        if(root->right==NULL)
            return l+root->data;
        
    }
    int maxPathSum(Node* root)
    {
        // just we have take from leaf node
        
        int res=INT_MIN;
        int ans=solve(root, res);
        if(!root->left || !root->right)
            res=max(res,ans);
        return res;
    }