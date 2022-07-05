    void maxlevel(TreeNode* root, unordered_map<int,int>&m, int level)
    {
        if(root==NULL)
            return;
        m[level]=m[level]+root->val;

        
        maxlevel(root->left,m,level+1);
        maxlevel(root->right,m,level+1);
        return;
    }
    int maxLevelSum(TreeNode* root) {
        
        //i will store addition of all level into map
        unordered_map<int,int> m;
        if(root==NULL)
            return 0;
        int level=1;
        maxlevel(root, m, level);
        int ans=INT_MIN;
        int res=0;
        for(auto it:m)
            cout<<it.first<<" "<<it.second<<endl;
        for(auto i:m)
        {
            if(i.second>=ans)
            {
                ans=max(ans,i.second);
                res=i.first;
            }
        }
            
       return res; 
    }